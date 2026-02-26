#include <iostream>

using namespace std;

// Declaration of the non-smoking bus class.
class Autobus {
public:
    int nbPassagers = 0;
    int tempsVoyage = 3;
    string typeVoyage = "Non-Fumeur";
    string destination = "New-York";

    void ajouterPassager()
    {
        if (nbPassagers == 40)
            return;
        nbPassagers = nbPassagers + 1;
    }

    void afficherVoyage()
    {
        cout << endl << endl;
        cout << "Informations détaillées sur le voyage :" << endl << endl;
        cout << "Destination : " << destination << endl;
        cout << "Type de voyage : " << typeVoyage << endl;
        cout << "Durée totale du voyage aller-retour : " << tempsVoyage << " h" << endl;
        cout << "Nombre de passagers dans l'autobus : " << nbPassagers << endl << endl;
    }
};

// Declaration of the derived smoking bus class.
class AutobusFumeur : public Autobus {
public:
    string typeVoyage = "Fumeur";

    void afficherVoyage()
    {
        cout << endl << endl;
        cout << "Informations détaillées sur le voyage :" << endl << endl;
        cout << "Destination : " << destination << endl;
        cout << "Type de voyage : " << typeVoyage << endl;
        cout << "Durée totale du voyage aller-retour : " << tempsVoyage << " h" << endl;
        cout << "Nombre de passagers dans l'autobus : " << nbPassagers << endl << endl;
    }
};


int main()
{
    // Declaration of variables.
    string choix = "";

    // Instantiation of the Autobus and AutobusFumeur classes. Creation of objects A and AF.
    Autobus A;
    AutobusFumeur AF;

    // Display of the header.
    cout << "Logiciel de réservation \"Je voyage à New-York seulement\"." << endl;

    // Main loop.
    while ((A.nbPassagers < 40) || (AF.nbPassagers < 40))
    {
        // Input of the desired bus type, either non-smoking or smoking.
        cout << endl << "- Appuyer sur 1 pour non-fumeurs." << endl;
        cout << "- Appuyer sur 2 pour fumeurs." << endl;
        getline(cin, choix);

        // Validation of the entered choice.
        while (choix != "1" && choix != "2")
        {
            cout << "Erreur! Veuillez entrer un choix valide. Soit 1 pour non fumeurs ou 2 pour fumeurs :" << endl;
            getline(cin, choix);
        }

        // Handling of the choice.
        if (choix == "1")
        {
            if (A.nbPassagers < 40)
            {
                A.ajouterPassager();
                A.afficherVoyage();
            }
            else
            {
                cout << endl << "Cet autobus est maintenant plein. Veuillez en choisir un autre." << endl;
            }
        }
        else if (choix == "2")
        {
            if (AF.nbPassagers < 40)
            {
                AF.ajouterPassager();
                AF.afficherVoyage();
            }
            else
            {
                cout << endl << "Cet autobus est maintenant plein. Veuillez en choisir un autre." << endl;
            }
        }
    }

    // End message when both buses are full.
    cout << "Les deux autobus sont maintenant remplis." << endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Map to hold frequency
    map<string, int> frequencyMap;
    string item;

    // Open input file
    ifstream inFile("C:\\Users\\karlo\\Desktop\\project3\\Project3\\x64\\Debug\\CS210_Project_Three_Input_File.txt");
    if (!inFile) {
        cout << "Error: could not open input file." << endl;
        return 1;
    }
    else {
        cout << "File opened successfully!" << endl;
    }


    // Read items into map
    while (inFile >> item) {
        frequencyMap[item]++;
    }
    inFile.close();

    // Write output file
    ofstream outFile("frequency.dat");
    for (auto const& pair : frequencyMap) {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();

    // Menu loop
    int choice = 0;
    while (choice != 4) {
        cout << "\n1. Look up frequency of an item" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter item name: ";
            string searchItem;
            cin >> searchItem;
            cout << searchItem << " " << frequencyMap[searchItem] << endl;
        }
        else if (choice == 2) {
            for (auto const& pair : frequencyMap) {
                cout << pair.first << " " << pair.second << endl;
            }
        }
        else if (choice == 3) {
            for (auto const& pair : frequencyMap) {
                cout << pair.first << " ";
                for (int i = 0; i < pair.second; i++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

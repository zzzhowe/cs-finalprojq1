#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ==================== REQUIRED FUNCTIONS ====================

// Function 1: calculate average of 5 grades
float calculateAverage(float g1, float g2, float g3, float g4, float g5) {
    return (g1 + g2 + g3 + g4 + g5) / 5.0;
}

// Function 2: find highest grade value and name
float findHighest(float g1, float g2, float g3, float g4, float g5) {
    float highest = g1;
    if (g2 > highest) highest = g2;
    if (g3 > highest) highest = g3;
    if (g4 > highest) highest = g4;
    if (g5 > highest) highest = g5;
    return highest;
}
string highestGradeName ( float g1, float g2, float g3, float g4, float g5) { // checks each subject to find one with highest grade
    float highestgrade = g1;
    string highestName = "Math";

    if (g2 > highestgrade) {
        highestgrade = g2;
        highestName = "Science";
    }
    if (g3 > highestgrade) {
        highestgrade = g3;
        highestName = "English";
    }
    if (g4 > highestgrade) {
        highestgrade = g4;
        highestName = "History";
    }
    if (g5 > highestgrade) {
        highestgrade = g5;
        highestName = "Art";
    }
    return highestName;
}

// Function 3: find lowest grade value and name
float findLowest(float g1, float g2, float g3, float g4, float g5) {
    float lowest = g1;
    if (g2 < lowest) lowest = g2;
    if (g3 < lowest) lowest = g3;
    if (g4 < lowest) lowest = g4;
    if (g5 < lowest) lowest = g5;
    return lowest;
}
string lowestGradeName (float g1, float g2, float g3, float g4, float g5) { // checks each subject to see which one has the lowest grade
    float lowestgrade = g1;
    string lowestName = "Math";

    if (g2 < lowestgrade) {
        lowestgrade = g2;
        lowestName = "Science";
    }
    if (g3 < lowestgrade) {
        lowestgrade = g3;
        lowestName = "English";
    }
    if (g4 < lowestgrade) {
        lowestgrade = g4;
        lowestName = "History";
    }
    if (g5 < lowestgrade) {
        lowestgrade = g5;
        lowestName = "Art";
    }
    return lowestName;
}

// Function 4: get grade equivalent based on average
float getGrade(float average) { // uses the given formula to convert each input
    float Gmin = 1.0f;
    float Gmax = 5.0f;
    float Pmin = 1.0f;
    float Pmax = 100.0f;

    float newgrade = Gmax + ((average - Pmin) * (Gmin - Gmax)) / (Pmax - Pmin);

    if (newgrade < Gmin) newgrade = Gmin;
    if (newgrade > Gmax) newgrade = Gmax;

    return newgrade;
}


// Function 5: count number of passing grades
int countPassing(float g1, float g2, float g3, float g4, float g5) {
    int passCount = 0;
    if (g1 >= 60) passCount++;
    if (g2 >= 60) passCount++;
    if (g3 >= 60) passCount++;
    if (g4 >= 60) passCount++;
    if (g5 >= 60) passCount++;
    return passCount;
}

// ==================== EXTRA FEATURES ====================

// Input validation (keeps asking until input is valid)
float validatedInput(string subject) {
    float grade;
    while (true) {
        cout << "Enter " << subject << " grade (0-100): ";
        cin >> grade;
        if (cin.fail() || grade < 0 || grade > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
        } else {
            break;
        }
    }
    return grade;
}

// Director’s List check (true if gwa <= 1.5)
bool isDirectorsList(float gwa) {
    return gwa <= 1.5;
}

// ==================== MAIN PROGRAM ====================
int main() {
    // Student details
    string name, gradeLevel;
    int id, age;

    // Grades
    float math, science, english, history, art;

    cout << "========================================\n";
    cout << "        STUDENT GRADE CALCULATOR\n";
    cout << "========================================\n\n";

    // Profile setup
    cout << "=== STUDENT PROFILE SETUP ===\n";
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter student age: ";
    cin >> age;
    cin.ignore(); // clear buffer
    cout << "Enter grade level: ";
    getline(cin, gradeLevel);

    cout << "\nProfile created successfully!\n\n";

    // Grade entry with validation
    cout << "=== GRADE ENTRY ===\n";
    math = validatedInput("Math");
    science = validatedInput("Science");
    english = validatedInput("English");
    history = validatedInput("History");
    art = validatedInput("Art");

    cout << "\nGrades recorded successfully!\n\n";

    // Do the calculations
    float average = calculateAverage(math, science, english, history, art);
    string highestName = highestGradeName(math, science, english, history, art);
    string lowestName = lowestGradeName(math, science, english, history, art);
    
    float highest = findHighest(math, science, english, history, art);
    float lowest = findLowest(math, science, english, history, art);
    int passing = countPassing(math, science, english, history, art);
    float gwa = getGrade(average)
    ;bool dlStatus = isDirectorsList(gwa);

    int birthYear = 2025 - age; // simple extra info

    // Report card output
    cout << "========================================\n";
    cout << "           STUDENT REPORT CARD\n";
    cout << "========================================\n\n";

    cout << "STUDENT INFORMATION:\n";
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Age: " << age << " years old\n";
    cout << "Grade Level: " << gradeLevel << "th\n";
    cout << "Birth Year: " << birthYear << endl;

    cout << "\nSUBJECT GRADES:\n";
    cout << fixed << setprecision(1);
    cout << "Math: " << math << "%\n";
    cout << "Science: " << science << "%\n";
    cout << "English: " << english << "%\n";
    cout << "History: " << history << "%\n";
    cout << "Art: " << art << "%\n";

    cout << "\nGRADE STATISTICS:\n";
    float avg = calculateAverage(math, science, english, history, art);
    cout << fixed << setprecision(2);
    cout << "Average Grade: " << average << "%\n";
    cout << "Grade Equivalent: " << gwa << endl;
    cout << "Highest Grade: " << highestName << " (" << highest << "%)" << endl;
    cout << "Lowest Grade: " << lowestName << " (" << lowest << "%)" << endl;
    cout << "Subjects Passing: " << passing << " out of 5\n";
    
// uses if-else to determine if GWA is applicable to DL
    cout << "\nGWA: " << gwa << endl;
    if (dlStatus) {
        cout << "Director’s List Status: YES (Congratulations!)\n";
    } else {
        cout << "Director’s List Status: NO\n";
    }

    cout << "\n========================================\n";

    return 0;
}

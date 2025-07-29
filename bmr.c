#include <stdio.h>
#include <string.h>

// Function to return activity factor based on activity level input
float getActivityFactor(int level) {
    switch(level) {
        case 1: return 1.2;    // Sedentary (little or no exercise)
        case 2: return 1.375;  // Lightly active (light exercise/sports 1-3 days/week)
        case 3: return 1.55;   // Moderately active (moderate exercise/sports 3-5 days/week)
        case 4: return 1.725;  // Very active (hard exercise/sports 6-7 days/week)
        case 5: return 1.9;    // Extra active (very hard exercise or physical job)
        default: return 1.2;   // Default to Sedentary if invalid input
    }
}

int main() {
    int age, activityLevel;
    float height, weight, bmr, maintenanceCalories;
    char gender[10];

    // Program introduction
    printf("=== Calorie Maintenance Calculator ===\n");
    printf("This program calculates your Basal Metabolic Rate (BMR) and daily calorie needs for maintenance, weight loss, and weight gain.\n");

    // Input: Age, Height, Weight, Gender
    printf("Enter your age (in years): ");
    scanf("%d", &age);

    printf("Enter your height (in cm): ");
    scanf("%f", &height);

    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);

    printf("Enter your gender (Male/Female): ");
    scanf("%s", gender);

    // Select activity level
    printf("\nSelect your activity level:\n");
    printf("1. Sedentary (little or no exercise)\n");
    printf("2. Lightly Active (light exercise or sports 1-3 days/week)\n");
    printf("3. Moderately Active (moderate exercise or sports 3-5 days/week)\n");
    printf("4. Very Active (hard exercise or sports 6-7 days/week)\n");
    printf("5. Extra Active (very hard exercise or physical job)\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &activityLevel);

    // Calculate BMR based on gender
    if (strcmp(gender, "Male") == 0 || strcmp(gender, "male") == 0) {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;  // Harris-Benedict equation for males
    } else {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161; // Harris-Benedict equation for females
    }

    // Get the activity factor for maintenance calories calculation
    float activityFactor = getActivityFactor(activityLevel);
    maintenanceCalories = bmr * activityFactor;

    // Output the results
    printf("\n=== Results ===\n");
    printf("Your Basal Metabolic Rate (BMR) is: %.2f calories/day\n", bmr);
    printf("Your Maintenance Calories are: %.2f calories/day\n", maintenanceCalories);
    printf("To gain weight (surplus): %.2f calories/day\n", maintenanceCalories + 500);
    printf("To lose weight (deficit): %.2f calories/day\n", maintenanceCalories - 500);

    return 0;
}

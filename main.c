#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int doneShopping = 0;
int playerInput;
char playerCharInput;
char Y = 'y';

// player value storage           ********TODO: ADD BIT MANIPULATION FOR SOME INTS FOR SPACE SAVINGS********
int cash = 400.00;
int bill = 0.00;
int oxen = 0;
int food = 0;
int clothing = 0;
int ammunition = 0;


// travel info
int city;
int leftAt;        // 0 = march, 1 = april, 2 = may, 3 = june, 4 = july 
int Class;         // 0 =  farmer, 1 = carpenter, 2 = banker
int date = 1;
int month = 1; //1-12 normal months
int weather = 1;       // 1 = clear sky, 2 = cloudy, 3 = rainy, 4 = lightly rainy, 5 = thunderstorm, 6 = tornado, 7 = sandstorm

//
int distanceTraveled = 0;
int rand2;

// spare parts
int wagonWheel;
int wagonAxle;
int wagonTongue;

char leader[20];
char character2[20];
char character3[20];
char character4[20];
char character5[20];

void openSavedGame() {
    printf("doesn't work yet");
}

int returnRandom(int max) { // make int to return a random number
	// return with random c function
    return rand() % (max + 1);
}

void travel() {

}

void checkSupplies() {
	printf("\033[2JYou have:\n$%d\n%d Oxen\n%d Pounds of Food\n%d Spare Sets of Clothing\n%d Rounds of Ammunition\n%d Wagon Wheels\n%d Wagon Axles \n%d Wagon Tongues\n", cash, oxen, food, clothing, ammunition, wagonWheel, wagonAxle, wagonTongue);
}

void map() {

}

void changePace() {

}

void changeRations() {

}

void attemptToRest() {
	printf("\033[2JYou attempt to rest\n");
	//rand2 = returnRandom(100);
	// persentage table for randoms
	// 1 - 55 you rest successfully
	// 56 - 65 your oxen are stolen ( run random for ammount) 
	// 66 - 70 You are attcked by native americans
	
	
}


void setCharacterNames() {
    printf("\033[2JPlease input a name for the leader\n");
    scanf(" %19s", leader);
    printf("\033[2J\nHow many companions would you like?(max 4)\n");
    scanf(" %d", &playerInput);
    switch(playerInput) {
        case 1:
            printf("\n\033[2Jput in the name of your companion\n");
            scanf(" %19s", character2);
            printf("\033[2JAre these names right?(y/n)\n%s\n%s\n", leader, character2);
            scanf(" %c", playerCharInput);
            // -------------------------- Check if they are right -------------------------- //
            if (!playerCharInput == 'y') {
                printf("\033[2JPlease input a name for the leader\n");
                scanf(" %19s", leader);
                printf("\n\033[2Jput in the name of your companion\n");
                scanf(" %19s", character2);
            }
            // ----------------------------------------------------------------------------- //
            break;
        case 2:
            printf("\n\033[2Jput in the name of your first companion\n");
            scanf(" %19s", character2);
            printf("\n\033[2Jput in the name of your second companion\n");
            scanf(" %19s", character3);
            printf("are these names right?(y/n)\n%s\n%s\n%s\n", leader, character2, character3);
            scanf(" %19c", playerCharInput);
            // -------------------------- Check if they are right -------------------------- //
            if (!playerCharInput == 'y') {
                printf("\033[2JPlease input a name for the leader\n");
                scanf(" %19s", leader);
                printf("\n\033[2Jput in the name of your companion\n");
                scanf(" %19s", character2);
                printf("\n\033[2Jput in the name of your second companion\n");
                scanf(" %19s", character3);
            }
            // ----------------------------------------------------------------------------- //
        case 3:
            printf("\n\033[2Jput in the name of your first companion\n");
            scanf(" %19s", character2);
            printf("\n\033[2Jput in the name of your second companion\n");
            scanf(" %19s", character3);
            printf("\n\033[2Jput in the name of your third companion\n");
            scanf(" %19s", character4);
            // -------------------------- Check if they are right -------------------------- //
            printf("are these names right?(y/n)\n%s\n%s\n%s\n%s\n", leader, character2, character3, character4);
            scanf(" %c", playerCharInput);
            if (!playerCharInput == 'y') {
                printf("\033[2JPlease input a name for the leader\n");
                scanf(" %19s", leader);
                printf("\n\033[2Jput in the name of your companion\n");
                scanf(" %19s", character2);
                printf("\n\033[2Jput in the name of your second companion\n");
                scanf(" %19s", character3);
                printf("\n\033[2Jput in the name of your third companion\n");
                scanf(" %19s", character4);
            }
            // ----------------------------------------------------------------------------- //
            break;
        case 4:
            printf("\n\033[2Jput in the name of your first companion\n");
            scanf(" %19s", character2);
            printf("\n\033[2Jput in the name of your second companion\n");
            scanf(" %19s", character3);
            printf("\n\033[2Jput in the name of your third companion\n");
            scanf(" %19s", character4);
            printf("\n\033[2Jput in the name of your fourth companion\n");
            scanf(" %19s", character5);
            // -------------------------- Check if they are right -------------------------- //
            printf("are these names right?(y/n)\n%s\n%s\n%s\n%s\n%s\n", leader, character2, character3, character4, character5);
            scanf(" %c", playerCharInput);
            if (!playerCharInput == 'y') {
                printf("\033[2JPlease input a name for the leader\n");
                scanf(" %19s", leader);
                printf("\n\033[2Jput in the name of your companion\n");
                scanf(" %19s", character2);
                printf("\n\033[2Jput in the name of your second companion\n");
                scanf(" %19s", character3);
                printf("\n\033[2Jput in the name of your third companion\n");
                scanf(" %19s", character4);
                printf("\n\033[2Jput in the name of your fourth companion\n");
                scanf(" %19s", character5);
            }
            // ----------------------------------------------------------------------------- //
            break;
    }    
}

void shopLoop() {
    switch(playerInput) {
        case 1:             // Oxen
            printf("\033[2JThere are two oxen in a yoke. I recommend at least three yoke and I charge $40 a yoke.\nHow many yoke do you want\n");
            scanf(" %d", &playerInput);
            if (cash - playerInput * 40 >= 0) {
                cash = cash - (playerInput * 40);
                bill = bill + (playerInput * 40);
                oxen = oxen + playerInput;
            }
            else {
                printf("You do not have enough money");
            }
            break;
        case 2:             // Food
            printf("\033[2JI sell food in packs of 5 pounds for a dollar each. I recommend at least 200 pounds of food per family member.\n How many packs would you like to buy?\n");
            scanf(" %d", &playerInput);
            if (cash - playerInput >= 0) {
                cash = cash - (playerInput);
                bill = bill + (playerInput);
                food = food + (playerInput * 5);
            }
            else {
                printf("You do not have enough money");
            }
            break;
        case 3:         // Clothing
            printf("\033[2JYou'll need warm clothing for the mountians. I recommend at least 2 sets of clothing per person. each set is $10\n");
            scanf(" %d", &playerInput);
            if (cash - playerInput * 10 >= 0) {
                cash = cash - (playerInput * 10);
                bill = bill + (playerInput * 10);
                clothing = clothing + playerInput;
            }
            else {
                printf("You do not have enough money");
            }
            break;
        case 4:         // Ammunition
            printf("\033[2JI sell ammunition in boxes of 20 bullets. Each box holds 20 bullets and costs $2\n");
            scanf(" %d", &playerInput);
            if (cash - playerInput * 2 >= 0) {
                cash = cash - (playerInput * 2);
                bill = bill + (playerInput * 2);
                ammunition = ammunition + (playerInput*20);
            }
            else {
                printf("You do not have enough money");
            }
            break;
        case 5:         // Spare Parts
            printf("\033[2JIts a good idea to have a few spare parts for your wagon on the trail. Here are the prices:\n wagon wheel  -  $10 each\n wagon axle  -  $10 each\n wagon tongue  -  $each\n\nHow many wagon wheels?\n");
            scanf(" %d", &playerInput);
            if (cash - playerInput * 10 >= 0) {
                cash = cash - (playerInput * 10);
                bill = bill + (playerInput * 10);
                wagonWheel = wagonWheel + playerInput;
            }
            else {
                printf("You do not have enough money");
            }
            printf("\033[2JIts a good idea to have a few spare parts for your wagon on the trail. Here are the prices:\n wagon wheel  -  $10 each\n wagon axles  -  $10 each\n wagon tongues  -  $each\n\nHow many wagon axles?\n");
            scanf(" %d", &playerInput);
            if (cash - playerInput * 10 >= 0) {
                cash = cash - (playerInput * 10);
                bill = bill + (playerInput * 10);
                wagonAxle = wagonAxle + playerInput;
            }
            else {
                printf("You do not have enough money");
            }
            printf("\033[2JIts a good idea to have a few spare parts for your wagon on the trail. Here are the prices:\n wagon wheel  -  $10 each\n wagon axles  -  $10 each\n wagon tongues  -  $10 each\n\nHow many wagon tongues?\n");
            scanf(" %d", &playerInput);
            if (cash - playerInput * 10 >= 0) {
                cash = cash - (playerInput * 10);
                bill = bill + (playerInput * 10);
                wagonTongue = wagonTongue + playerInput;
            }
            else {
                printf("You do not have enough money");
            }
            break;
        case 6:
            printf("\033[2JYou have $%d left,\n Your current bill is $%d,\nCurrent supplies:\n   %d yokes of oxen,\n   %d pounds of food,\n   %d pairs of clothing,\n   %d rounds of ammunition,\n   %d spare wheels,\n   %d spare axles,\n   %d spare wagon tongues\n\n Press any letter then enter to continue\n", oxen, food, clothing, ammunition, wagonWheel, wagonAxle, wagonTongue);
            scanf(" %1s", playerCharInput);
            break;
    }
}

void shop() {
    while (doneShopping == 0) {
        printf("\033[2J\033[0;41m                                                                                                                                                                           \n");
        printf("\033[0;49m General Store, Independence Missouri                                                                                                                                                                                           \n                      ");
        // string switch statement for the month
        switch(leftAt) {
            case 0:
                printf("March ");
                break;
            case 1:
                printf("April ");
                break;
            case 2:
                printf("May ");
                break;
            case 3:
                printf("June ");
                break;
            case 4:
                printf("July ");
                break;
        }

        printf("1,  1848                                                                                                                                                                                              \n\033[0;41m                                                                                                                                                                         \033[0;49m\n\n");
        printf("\033[0;49m1. Oxen\n2. Food\n3. Clothing\n4. Ammunition\n5. Spare parts\n6. Check my supplies\n\033[0;41m                                                                                                                                                                         \033[0;49m\n         Total Bill:    $%d.00   \n         You have:    $%d\n Which item would you like to buy?\n", bill, cash);
        scanf(" %d", &playerInput);
        shopLoop();
        printf("/033[2JWould you like to leave the store?(y/n)\n");
        scanf(" %c", &playerCharInput);
        doneShopping = (playerCharInput == 'y')?  1 : 0;
        playerCharInput = 'a';
    }
    printf("Good luck you have a long journey ahead of you");
}

void gameLoop() {
    while (1) {
        //     city       //
        //    date  year  //
        //                //
        // weather:       //
        // rations:       // 
        // Pace:          //
        // rations        //
        // you may:
        //  1. Travel the trail
        //  2. check supplies
        //  3. Look at map
        //  4. Change Pace
        //  5. change food rations
        //  6. attempt to rest
        switch(city) { // print city/if on the trail print that
            case 1:
                printf("                    Independence, Missouri\n");
                break;
            case 2:
                printf("                    Chimney Rock, Nebraska");
                break;
            case 3:
                printf("                    Scotts Bluff, Nebraska");
                break;
            case 4:
                printf("                    Fort Laramie, Wyoming");
                break;
       	    case 5:
                printf("                  Independence Rock, Wyoming");
                break;
            case 6:
                printf("                     South Pass, Wyoming");
                break;
            case 7:
                printf("                 Three Island Crossing, Idaho");
                break;
            case 8:
                printf("                       Fort Hall, Idaho");
                break;
            case 9:
                printf("                      Oregon City, Oregon");
                break;
        }
        switch(month) { // print month
            case 1:
                printf("                         January");
                break;
            case 2:
                printf("                        February");
                break;
            case 3:
                printf("                           March");
                break;
            case 4:
                printf("                           April");
                break;
            case 5:
                printf("                             May");
                break;
            case 6:
                printf("                            June");
                break;
            case 7:
                printf("                            July");
                break;
            case 8:
                printf("                          August");
                break;
            case 9:
                printf("                       September");
                break;
            case 10:
                printf("                         October");
                break;
            case 11:
                printf("                        November");
                break;
            case 12:
                printf("                        December");
                break;
            default:
                printf("                           March");
                break;
        }
        switch(date) { // print date
            case 1:
                printf("1st,\n");
                break;
            case 2:
                printf("2nd,\n");
                break;
            case 3:
                printf("3rd,\n");
                break;
            case 21:
                printf("21st,\n");
                break;
            case 22:
                printf("22nd,\n");
                break;
            case 23:
                printf("23rd,\n");
                break;
            case 31:
                printf("31st,\n");
                break;
            default:
                printf("%dth,\n", date);
                break;
        }
        switch(weather) { // 1 clear skies, 2 cloudy, 3 rainy, 4 lightly rainy, 5 thunderstorm, 6 tornado, 7 sandstorm
            case 1:
            printf("\n                     Weather: Clear Skies\n");
            break;
            case 2:
	    printf("\n                       Weather: Cloudy\n");
            break;
            case 3:
	    printf("\n                       Weather: Rainy");
            break;
            case 4:
	    printf("\n                   Weather: Lightly Rainy");
            break;
            case 5:
	    printf("\n                   Weather: Thunderstorming")
            break;
            case 6:
	    printf("\n                      Weather: Tornado");
            break;
            case 7:
            break;
        }

        printf("What would you like to do?\n1. Travel The Trail\n2. Check Supplies\n3. Look at Map\n4. Change Pace\n5. Modify Rations\n6. Attempt to Rest\n");
	scanf(" %d", &playerInput);
	(playerInput > 4)? (playerInput == 6)? printf("resting\n") : printf("Checking Rations\n"): (playerInput > 2)? (playerInput == 4) ? printf("Changing Pace\n") : printf("Checking Map\n") : (playerInput == 2) ? checkSupplies() : printf("Traveiling the trail\n");
	scanf(" %c", playerCharInput);
    }
}

void newGame() {
    // select class
    printf("You can play as 3 different people.\n1) Farmer\n2) Carpenter\n3) Banker\n");
    scanf(" %d", &playerInput);
    switch (playerInput) {
    case 1:
        printf("/033[2JFarmer Chosen\n\033[1;37mPress any letter than enter to continue\033[0;37m\n");
        Class = 0;
        cash = 600.00;
        break;
    case 2:
        printf("/033[2JCarpenter Chosen\n\033[1;37mPress any letter than enter to continue\033[0;37m\n");
        Class = 1;
        cash = 800.00;
        break;
    case 3:
        printf("/033[2JBanker Chosen\n\033[1;37mPress any letter than enter to continue\033[0;37m\n");
        Class = 2;
        cash = 1200.00;
        break;
    default:
        break;
    }

    setCharacterNames();

    // time leaving
    printf("\033[2JWhen would you like to leave?\n1) March\n2) April\n3) May\n4) June\n5) July\n6) Ask for advice\n");
    scanf(" %d", &playerInput);
    switch(playerInput) {
        case 1:
            printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
            scanf(" %s", &playerInput);
            leftAt = 0;
            break;
        case 2:
            printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
            scanf(" %s", &playerInput);
            leftAt = 1;
            break;
        case 3:
            printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
            scanf(" %s", &playerInput);
            leftAt = 2;
            break;
        case 4:
            printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
            scanf(" %s", &playerInput);
            leftAt = 3;
            break;
        case 5:
            printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
            scanf(" %s", &playerInput);
            leftAt = 4;
            break;
        case 6:
            printf("\n\033[2JYou attend a meeting for \"Folks with Oregon Fever\" You are told:\n\n If you leave too early your oxen will not have enough grass to eat, and if you leave too late you won't make it before winter, but if you leave at the right time\n you will have green grass and nice weather\n \033[1;37mPress any letter key then enter to continue\033[0;37m");
            scanf(" %s", &playerInput);
            printf("\033[2JWhen would you like to leave?\n1) March\n2) April\n3) May\n4) June\n5) July\n6) Ask for advice");
            scanf(" %s", &playerInput);
            switch(playerInput) {
                case 1:
                    printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
                    scanf(" %s", &playerInput);
                    leftAt = 0;
                    break;
                case 2:
                    printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
                    scanf(" %s", &playerInput);
                    leftAt = 1;
                    break;
                case 3:
                    printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
                    scanf(" %s", &playerInput);
                    leftAt = 2;
                    break;
                case 4:
                    printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m", cash);
                    scanf(" %s", &playerInput);
                    leftAt = 3;
                    break;
                case 5:
                    printf("\n\033[2JBefore leaving you should purchase equipment and supplies. You have $%d in cash, but you don't have to spend it all now.\n\033[1;37mPress any letter key then enter to continue\033[0;37m\n", cash);
                    scanf(" %s", &playerInput);
                    leftAt = 4;
                    break;
                }
            break;
    }

    // prepare for leaving
    shop();
    gameLoop();
}

int main() {
    printf("Welcome to a remake of Oregon Trail\nWould you like to start a new game(1) or open a saved one(2)?(1/2)\n");
    // scanf(" %d", &playerInput);
    // (playerInput == 1)? newGame(): openSavedGame();
    //shop();
    gameLoop();

    return 0;
}

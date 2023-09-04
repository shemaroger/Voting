#include<stdio.h>
#include<string.h>

#define CANDIDATE_COUNT 4
#define MAX_NAME_LENGTH 50
#define MAX_VOTER_COUNT 100

struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct voter {
    int id;
    char name[MAX_NAME_LENGTH];
};

struct candidate Candidates[CANDIDATE_COUNT] = {
    {"SHEMA Roger", 0},
    {"MUSONI Aime Kevine", 0},
    {"MAHORO Charity", 0},
    {"KAYIRANGA Chriss Bebeto", 0}
};

int spoiledtvotes = 0;
int total_voters = 0;
struct voter Voters[MAX_VOTER_COUNT];

void CAST_VOTE() {
    int choice;
    int voter_id;
    char voter_name[MAX_NAME_LENGTH];

    printf("\n\n ### Please enter your Voter national ID and Name ###\n\n");
    printf("Enter your national ID: ");
    scanf("%d", &voter_id);
    printf("Enter your full Name: ");
    scanf("%s", voter_name);

    // Check if the voter has already voted
    for (int i = 0; i < total_voters; i++) {
        if (Voters[i].id == voter_id) {
            printf("\nERROR: You have already voted!\n");
            return;
        }
    }

    Voters[total_voters].id = voter_id;
    strcpy(Voters[total_voters].name, voter_name);
    total_voters++;

    printf("\n\n ### Please choose your Candidate ###\n\n");
    for(int i=0; i<CANDIDATE_COUNT; i++){
        printf("\n %d. %s", i+1, Candidates[i].name);
    }
    printf("\n %d. %s", CANDIDATE_COUNT+1, "None of These");

    printf("\n\n Input your choice (1 - %d) : ", CANDIDATE_COUNT+1);
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            Candidates[0].votes++;
            break;
        case 2:
            Candidates[1].votes++;
            break;
        case 3:
            Candidates[2].votes++;
            break;
        case 4:
            Candidates[3].votes++;
            break;
        case 5:
            spoiledtvotes++;
            break;
        default:
            printf("\n ERROR: Wrong Choice !! Please retry");
            //hold the screen
            getchar();
    }
    printf("\n Thanks for voting, %s !!", voter_name);
}

void VOTES_COUNTER(){
    printf("\n\n ##### Voting Statistics ####");
    for(int i=0; i<CANDIDATE_COUNT; i++){
        printf("\n %s : %d ", Candidates[i].name, Candidates[i].votes);
    }
    printf("\n %s : %d ", "Spoiled Votes", spoiledtvotes);
}

void Display_WINNER(){
    printf("\n\n  ### -----WINNER------####\n\n");
    int max_index = 0;
    for(int i=1; i<CANDIDATE_COUNT; i++){
        if(Candidates[i].votes > Candidates[max_index].votes){
            max_index = i;
        }
    }
    printf("The winner is [%s] with %d votes\n", Candidates[max_index].name, Candidates[max_index].votes);

    // Sort candidates by votes
    struct candidate temp_candidate;
    for(int i=0; i<CANDIDATE_COUNT-1; i++){
        for(int j=i+1; j<CANDIDATE_COUNT; j++){
            if(Candidates[i].votes < Candidates[j].votes){
                // Swap candidates
                temp_candidate = Candidates[i];
                Candidates[i] = Candidates[j];
                Candidates[j] = temp_candidate;
            }
        }
    }

    printf("\n\n  ### Ranking of candidates ####\n\n");
    for(int i=0; i<CANDIDATE_COUNT; i++){
        printf("%s : %d\n", Candidates[i].name, Candidates[i].votes);
    }
}


int main()
{
    int choice;
    do{
        printf("\n\n ###### WELCOME TO PRESIDENT ELECTION/VOTING 2023 #####");
        printf("\n\n 1. CAST THE VOTE");
        printf("\n 2. DISPLAY VOTING STATISTICS");
        printf("\n 3. REPORT OF THE ELECTION");
        printf("\n 0. ---EXIT---");
        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);
switch(choice)
{
case 1: CAST_VOTE();break;
case 2: VOTES_COUNTER();break;
case 3: Display_WINNER();break;
default: printf("\n Thank you for using our system!!!!\n");
}
}while(choice!=0);

//hold the screen
getchar();
getch();
return 0;
}


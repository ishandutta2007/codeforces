#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

char grid[8][9];

int main() {
    int white = 0;
    int black = 0;
    for (int i=0;i<8;i++) scanf(" %s",&grid[i]);
    for (int i=0;i<8;i++) for (int j=0;j<8;j++) {
        char piece = grid[i][j];
        if (piece=='Q') white+=9;
        if (piece=='R') white+=5;
        if (piece=='B') white+=3;
        if (piece=='N') white+=3;
        if (piece=='P') white+=1;
        if (piece=='q') black+=9;
        if (piece=='r') black+=5;
        if (piece=='b') black+=3;
        if (piece=='n') black+=3;
        if (piece=='p') black+=1;
    }
    if (white>black) printf("White\n");
    if (black>white) printf("Black\n");
    if (white==black) printf("Draw\n");

    return 0;
}
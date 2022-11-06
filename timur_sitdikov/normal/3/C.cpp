#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char s[3][5];

int check(char sym)
{
    int i;
    for(i=0; i<3; i++)
        if (s[i][0]==sym && s[i][0]==s[i][1] && s[i][1]==s[i][2]) return 1;
        else if (s[0][i]==sym && s[0][i]==s[1][i] && s[1][i]==s[2][i]) return 1;
    if (s[0][0]==sym && s[0][0]==s[1][1] && s[1][1]==s[2][2]) return 1;
    if (s[0][2]==sym && s[0][2]==s[1][1] && s[1][1]==s[2][0]) return 1;
    return 0;
}

int main()
{   
    int x=0, o=0, i, j, fx=0, fo=0;
    char tmp;
    for(i=0; i<3; i++)
        scanf("%s", &s[i]);
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if (s[i][j]=='X') x++;
            else if (s[i][j]=='0') o++;
    if (!(x==o || x==o+1))
    {printf("illegal");return 0;}
    if (check('X')) fx=1;
    if (check('0')) fo=1;
    if (fx && fo)
    {printf("illegal");return 0;}
    if (fx)
    {
        if (x!=o+1) {printf("illegal");return 0;}
        for(i=0; i<3; i++)
            for(j=0; j<3; j++)
            {
                tmp=s[i][j];
                s[i][j]='.';
                if (!check('X')){printf("the first player won"); return 0;}
                s[i][j]=tmp;
            }
        printf("illegal");return 0;
    }
    if (fo)
    {
        if (x!=o) {printf("illegal");return 0;}
        for(i=0; i<3; i++)
            for(j=0; j<3; j++)
            {
                tmp=s[i][j];
                s[i][j]='.';
                if (!check('X')){printf("the second player won"); return 0;}
                s[i][j]=tmp;
            }
        printf("illegal");return 0;
    }
    if (x+o==9) {printf("draw"); return 0;}
    if (x==o) printf("first");
    else printf("second");
}
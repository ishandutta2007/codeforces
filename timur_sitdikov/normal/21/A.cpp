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

char col[200];

int main()
{   
    int i, j, j1, l, last;
    char c[105];
    scanf("%s", &c);
    l=strlen(c);
    for(i='a'; i<='z'; i++) col[i]=1;
    for(i='A'; i<='Z'; i++) col[i]=1;
    for(i='0'; i<='9'; i++) col[i]=1;
    col['_']=1;
    for(i=0; i<l; i++)
    {
        if (c[i]=='@') break;
        if (!col[c[i]])
        {printf("NO"); return 0;}
    }
    if (i==l || i==0 ||  i>16){printf("NO"); return 0;}
    j=i+1;
    for(i++; i<l; i++)
    {
        if (c[i]=='/') break;
        if (!col[c[i]] && c[i]!='.')
        {printf("NO"); return 0;}
    }
    j1=i;
    if (j1-j>32 || j1==j) {printf("NO"); return 0;}
    last=j-1;
    for(i=j; i<j1; i++)
        if(c[i]=='.')
        {
            if (i-last==1 || i-last>17) {printf("NO"); return 0;}
            last=i;
        }
    if (c[j1-1]=='.' || j1-last>17) {printf("NO"); return 0;}
    for(i=j1+1; i<l; i++)
        if (!col[c[i]])
        {printf("NO"); return 0;}
    if (l-j1>17 || l==j1+1 && c[j1]=='/') {printf("NO"); return 0;}
    printf("YES");
        
}
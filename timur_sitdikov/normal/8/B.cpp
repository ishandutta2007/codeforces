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

int g[250][250];

int main()
{   
    char c[105];
    int i, j, k, i1, j1;
    scanf("%s", &c);
    g[125][125]=1;
    for(i=j=125, k=0; c[k]; k++)
    {
        if (c[k]=='U') i++;
        else if (c[k]=='D') i--;
        else if (c[k]=='L') j--;
        else j++;
        if (g[i][j])
        {
            printf("BUG"); return 0;
        }
        g[i][j]=k+2;
        for(i1=-1; i1<=1; i1++)
            for(j1=-1; j1<=1; j1++)
                if (abs(i1+j1)==1 && g[i+i1][j+j1] && g[i+i1][j+j1]!=k+1)
                {
                    printf("BUG"); return 0;
                }       
    }
    printf("OK");
}
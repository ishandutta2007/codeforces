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

int main()
{   
    char c[10][10];
    int i, j, ans=0, f;
    for(i=0; i<8; i++)
        scanf("%s", &c[i]);
    for(i=0; i<8; i++)
    {
        f=0;
        for(j=0; j<8; j++)
            if (c[i][j]=='W')
            {
                f=1; break;
            }
        if (!f) ans++;
    }
    if (ans==8) 
    {
        printf("%d", ans); return 0;
    }
    for(j=0; j<8; j++)
    {
        f=0;
        for(i=0; i<8; i++)
            if (c[i][j]=='W')
            {
                f=1; break;
            }
        if (!f) ans++;
    }
    printf("%d", ans);
}
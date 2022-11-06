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
#define point pair<int, int>
#define x first
#define y second

point pt[250];
char fl[250][4];

int main()
{   
 
    int i, j, n, ans=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d %d", &pt[i].x, &pt[i].y);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if (j!=i)
            {
                if (pt[i].x==pt[j].x)
                {
                    if (pt[i].y<pt[j].y) fl[i][0]=1;
                    else fl[i][1]=1;
                }
                else if (pt[i].y==pt[j].y)
                {
                    if (pt[i].x<pt[j].x) fl[i][2]=1;
                    else fl[i][3]=1;
                }
            }
    for(i=0; i<n; i++)
        if (fl[i][0] && fl[i][1] && fl[i][2] && fl[i][3])
            ans++;
    printf("%d", ans);
}
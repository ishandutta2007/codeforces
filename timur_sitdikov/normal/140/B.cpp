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

char g[305][305];
int d[305][305], d1[305];

int main()
{   
    int i, j, k, n, f;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &d[i][j]);
    for(i=0; i<n; i++)
        scanf("%d", &d1[i]);
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            g[d1[i]][d1[j]]=1;
    for(k=0; k<n; k++)
    {   
        for(i=0; i<n; i++)
        {
            f=0;
            if (d[k][i]!=k+1)
            {
                for(j=i+1; j<n; j++)
                    if (d[k][j]!=k+1 && g[d[k][j]][d[k][i]] && d[k][j]<d[k][i])
                    {f=1; break;}
                if (!f) break;
            }
        }
        printf("%d ", d[k][i]);
    }
}
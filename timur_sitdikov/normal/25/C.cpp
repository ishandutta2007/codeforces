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

long long g[2][305][305];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long i, j, a, b, k, c, m, n, ans;
    scanf("%I64d", &n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%I64d", &g[0][i][j]);
    scanf("%I64d", &m);
    for(k=1; k<=m; k++)
    {
        scanf("%I64d %I64d %I64d", &a, &b, &c);
        c=min(c, g[(k&1)^1][a][b]);
        ans=0;
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
            {
                g[k&1][i][j]=min(min(g[(k&1)^1][i][j], g[(k&1)^1][i][a]+g[(k&1)^1][j][b]+c), 
                    g[(k&1)^1][i][b]+g[(k&1)^1][j][a]+c);
                g[k&1][j][i]=g[k&1][i][j];
                ans+=g[k&1][i][j];
            }
        printf("%I64d ", ans);
    }
}
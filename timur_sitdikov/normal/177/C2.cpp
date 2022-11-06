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

char g[2005][2005];
int col[2005], n, f, cur;

void dfs(int s, int cl)
{
    int i;
    cur++;
    col[s]=cl;
    for(i=1; i<=n; i++)
        if (g[s][i]==1 && !col[i]) dfs(i, cl);
        else if (g[s][i]==2 && col[i]==cl) f=1;
}

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int m, i, a, b, j, ans=0, cl=0;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b]=g[b][a]=1;
    }
    scanf("%d", &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b]=g[b][a]=2;
    }
    for(i=1; i<=n; i++)
        if (!col[i]) 
        {
            cur=f=0;
            dfs(i, ++cl);
            if (cur>ans && !f) ans=cur;
        }
    printf("%d", ans);
}
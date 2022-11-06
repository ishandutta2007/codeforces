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

int g[1005][1005], col[1005];
int dis[1005], cost[1005];
int n, bi=1000*1000*1100;

int calc()
{
    int i, j, ans=0, mn, mini;
    for(i=1; i<=n; i++) dis[i]=bi;
    for(i=1; i<=n; i++)
    {
        mn=-1;
        for(j=1; j<=n; j++)
            if (!col[j] && mn<cost[j])
            {mn=cost[j]; mini=j;}
        if (i==1) dis[mini]=0;
        col[mini]=1;
        for(j=1; j<=n; j++)
            if (cost[j]<cost[mini])
                dis[j]=min(dis[j], g[mini][j]);
    }
    for(i=1; i<=n; i++)
    {
        if (dis[i]==bi) return bi;
        else ans+=dis[i];
    }
    return ans;
}

int main()
{   

    int maxi=-1, mx=-1, m, a, b, c, i, j, ans;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if (i!=j) g[i][j]=bi;
    for(i=1; i<=n; i++)
        scanf("%d", &cost[i]);

    scanf("%d", &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (g[a][b]>c) g[a][b]=c;
    }
    ans=calc();
    if (ans==bi) printf("-1");
    else printf("%d", ans);
}
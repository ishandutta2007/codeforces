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

int dis[50003][503], k;
long long ans;
char col[50003];
vector<int> g[50003];

void dfs(int s)
{
    int i, j, sz, tmp;
    col[s]=1;
    dis[s][0]=1;
    sz=g[s].size();
    for(i=0; i<sz; i++)
    {
        tmp=g[s][i];
        if (!col[tmp])
        {
            dfs(tmp);
            for(j=0; j<k; j++)
                ans+=(long long)dis[s][j]*(long long)dis[tmp][k-j-1];
            for(j=1; j<=k; j++)
                dis[s][j]+=dis[tmp][j-1];
        }
    }
}

int main()
{   
    int n, i, a, b;
    scanf("%d %d", &n, &k);
    for(i=1; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    printf("%I64d", ans);
}
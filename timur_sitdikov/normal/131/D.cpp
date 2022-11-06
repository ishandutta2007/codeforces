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

vector <int> g[3005];
char col[3005];
int n, v, f, prv[3005], dis[3005];
queue <int> qq;

int dfs(int s)
{
    int i, tmp, sz;
    col[s]=1;
    sz=g[s].size();
    for(i=0; i<sz; i++)
    {
        tmp=g[s][i];
        if (!col[tmp])
        {
            prv[tmp]=s;
            if (dfs(tmp))
            {
                if (f)
                    col[s]=2;
                if (s==v) f=0;
                return 1;
            }
        }
        else
        {
            if (prv[s]!=tmp)
            {
                f=1;
                v=tmp;
                col[s]=2;
                return 1;
            }
        }
    }
    return 0;
}

void bfs()
{
    int tmp, i, sz, v;
    while(!qq.empty())
    {
        tmp=qq.front();
        qq.pop();
        sz=g[tmp].size();
        for(i=0; i<sz; i++)
        {
            v=g[tmp][i];
            if (col[v]!=2)
            {
                col[v]=2;
                dis[v]=dis[tmp]+1;
                qq.push(v);
            }
        }
    }
}

int main()
{   

    int i, a, b;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for(i=1; i<=n; i++)
        if (col[i]==2)
        {
            qq.push(i); dis[i]=0;
        }
    bfs();
    for(i=1; i<=n; i++) printf("%d ", dis[i]);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <iostream>
#define Maxn 200007
using namespace std;
int n,k;
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int d[Maxn],dep[Maxn],r[Maxn];
bool vis[Maxn];
int lx=0,rx=0,que[Maxn];
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
        ++d[u],++d[v];
    }
    for (int i=1;i<=n;i++)
    {
        dep[i]=n;
        if (d[i]==1) que[++rx]=i,dep[i]=0;
    }
    memset(r,0,sizeof(r));
    memset(vis,false,sizeof(vis));
    int ans=0;
    bool flag=true;
    while (lx<rx)
    {
        int u=que[++lx];
        vis[u]=true;
        for (int q=last[u];q;q=pre[q])
        {
            int v=other[q];
            if (!vis[v])
            {
                --d[v];
                if (dep[v]==n) dep[v]=dep[u]+1; else if (dep[v]!=dep[u]+1) flag=false;
                ++r[v];
                if ((d[v]==1&&rx<n-1)||(d[v]==0&&rx==n-1))
                {
                    if (r[v]<3) flag=false;
                    vis[v]=true;
                    ans=max(ans,dep[v]);
                    que[++rx]=v;
                }
            }
        }
    }
    if (ans==k&&flag) printf("Yes\n"); else printf("No\n");
    return 0;
}
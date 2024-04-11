#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
 
using namespace std;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int dfn[110000], low[110000], instack[110000], stak[110000], belong[110000];
int head[110000], cnt, cost[110000], c[110000], d[110000];
int top, index, ans;
struct node
{
    int u, v, next;
}edge[1000000];
void add(int u, int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++index;
    instack[u]=1;
    stak[++top]=u;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        ans++;
        while(1)
        {
            int v=stak[top--];
            instack[v]=0;
            belong[v]=ans;
            if(u==v) break;
        }
    }
}
void init()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    top=index=ans=0;
    memset(c,0,sizeof(c));
    memset(cost,INF,sizeof(cost));
}
int main()
{
    int n, m, i, u, v;
    __int64 tot, cc;
    scanf("%d",&n);
    init();
    for(i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(i=1;i<=n;i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
    for(i=1;i<=n;i++)
    {
        if(cost[belong[i]]>d[i])
        {
            c[belong[i]]=1;
            cost[belong[i]]=d[i];
        }
        else if(cost[belong[i]]==d[i])
        {
            c[belong[i]]++;
        }
    }
    tot=1;
    cc=0;
    for(i=1;i<=ans;i++)
    {
        cc+=cost[i];
        tot=(tot*c[i])%mod;
    }
    printf("%I64d %I64d\n",cc,tot);
    return 0;
}
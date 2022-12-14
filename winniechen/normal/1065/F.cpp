#include <bits/stdc++.h>
#define maxn 1000100
#define INF 0x3f3f3f3f
using namespace std;

int n,k;
int tot,head[maxn];
int deep[maxn],size[maxn],low[maxn];
bool visit[maxn];

struct node
{
    int to,next;
}e[maxn<<1];

void addedge(int u,int v)
{
    e[++tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}

void dfs1(int x,int d)
{
    deep[x]=d;
    low[x]=INF;
    if(!visit[x])
        low[x]=d;
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        int y=e[i].to;
        dfs1(y,d+1);
        low[x]=min(low[x],low[y]);
    }
}

void dfs2(int v)
{
    if(!visit[v])  size[v]=1;
    for(int i=head[v];i!=-1;i=e[i].next)
    {
        int u=e[i].to;
        dfs2(u);
        if(low[u]-deep[v]<=k)
        {
            size[v]+=size[u];
            size[u]=0;
        }
    }
}

int answer(int u)
{
    int ret=0;
    for(int i=head[u];i!=-1;i=e[i].next)
        ret=max(ret,answer(e[i].to));
    return ret+=size[u];
}

int main()
{
    scanf("%d%d",&n,&k);
    memset(head,-1,sizeof(head));
    for(int i=2;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        addedge(a,i);
        visit[a]=1;
    }
    dfs1(1,0);
    dfs2(1);
    printf("%d",answer(1));
    return 0;
}
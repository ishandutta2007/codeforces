#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int n;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int max_son[Maxn],d[Maxn],size[Maxn],dep[Maxn];
int now;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    size[u]=1;
    d[u]=u;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dfs(v,u);
            size[u]+=size[v];
            if (size[v]>size[max_son[u]]) 
            {
                max_son[u]=v;
                d[u]=d[v];
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
    }
    dep[0]=-1;
    dfs(1,0);
    printf("d %d\n",1);
    fflush(stdout);
    scanf("%d",&now);
    int u=1;
    while (dep[u]!=now)
    {
        printf("d %d\n",d[u]);
        fflush(stdout);
        int dis;
        scanf("%d",&dis);
        dis=(now+dep[d[u]]-dis)/2-dep[u];
        for (int i=1;i<=dis;i++)
            u=max_son[u];
        if (dep[u]!=now)
        {
            printf("s %d\n",u);
            fflush(stdout);
            scanf("%d",&u);
        }
    }
    printf("! %d\n",u);
    fflush(stdout);
    return 0;
}
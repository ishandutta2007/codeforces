#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int fa[Maxn],rk[Maxn];
int n,m,c,q;
set<int> s[Maxn];
map<int,int> g[Maxn];
int get_father(int x)
{
    if (fa[x]==x) return x;
    fa[x]=get_father(fa[x]);
    return fa[x];
}
void merge(int u,int v)
{
    u=get_father(u),v=get_father(v);
    if (u==v) return;
    if (rk[u]<rk[v]) swap(u,v);
    rk[u]+=rk[v];
    fa[v]=u;
    s[u].insert(s[v].begin(),s[v].end());
    s[v].clear();
}
void add(int u,int v,int x)
{
    if (g[u][x]!=0) merge(g[u][x],v);
    if (g[v][x]!=0) merge(g[v][x],u);
    g[u][x]=v;
    g[v][x]=u;
    s[get_father(u)].insert(v);
    s[get_father(v)].insert(u);
}
void query(int u,int v)
{
    if (get_father(u)==get_father(v)) printf("Yes\n");
    else if (s[get_father(u)].count(v)) printf("Yes\n");
    else printf("No\n");
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&c,&q);
    for (int i=1;i<=n;i++)
    {
        fa[i]=i;
        rk[i]=1;
    }
    for (int i=1;i<=m;i++)
    {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        add(u,v,x);
    }
    while (q--)
    {
        char ch=getchar();
        while (ch!='?'&&ch!='+') ch=getchar();
        if (ch=='+')
        {
            int u,v,x;
            scanf("%d%d%d",&u,&v,&x);
            add(u,v,x);
        } else
        {
            int u,v;
            scanf("%d%d",&u,&v);
            query(u,v);
        }
    }
    return 0;
}
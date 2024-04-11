#include <bits/stdc++.h>
#define Maxn 4007
using namespace std;
int n;
int p[Maxn],tot[Maxn];
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int ans[Maxn],size[Maxn];
bool flag=true;
int r=0;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void process(int u,int fa,int c)
{
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            if (ans[v]>c) ++ans[v];
            process(v,u,c);
        }
    }
}
void dfs(int u,int fa)
{   
    if (!flag) return;
    for (int q=last[u];q&&flag;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dfs(v,u);
            size[u]+=size[v];
        }
    }
    if (size[u]<tot[u]) flag=false;
    if (!flag) return;
    ++size[u];
    ans[u]=++r;
    process(u,fa,r-size[u]+tot[u]);
    ans[u]=r-size[u]+tot[u]+1;
}
int main()
{
    scanf("%d",&n);
    int rt;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i],&tot[i]);
        if (p[i]!=0) insert(p[i],i),insert(i,p[i]); else rt=i;
    }
    dfs(rt,-1);
    if (!flag) printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
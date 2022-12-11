#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int p[Maxn],h[Maxn],sum[Maxn];
int T,n,m;
bool check=true;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
    sum[u]=p[u];
    int s=0;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dfs(v,u);
            sum[u]+=sum[v];
            s+=h[v];
        }
    }
    if (sum[u]%2!=(h[u]%2+2)%2) check=false;
    else if (h[u]>sum[u]) check=false;
    else if (h[u]<s-p[u]) check=false;
}
void solve()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        last[i]=0;
    }
    cnt=0;
    for (int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
    }
    check=true;
    dfs(1,-1);
    if (check) printf("YES\n"); else printf("NO\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}
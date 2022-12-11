#include <bits/stdc++.h>
using namespace std;
#define Maxn 1207
#define modp 998244353
int n,m;
int a[Maxn],b[Maxn];
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int dis[Maxn][Maxn];
int ans[Maxn][Maxn];
int d[Maxn];
bool vis[Maxn],vist[Maxn];
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
int deal(int k)
{
    for (int i=1;i<=n;i++)
        d[i]=0;
    for (int i=1;i<=n;i++)
        for (int q=last[i];q;q=pre[q])
        {
            int v=other[q];
            if (dis[k][v]==dis[k][i]-1) ++d[i];
        }
    int res=1;
    for (int i=1;i<=n;i++)
        if (i!=k) res=(1LL*res*d[i])%modp;
    return res;
}
int calc(int a,int b)
{
    for (int i=0;i<=n;i++)
        vis[i]=false,vist[i]=false;
    for (int i=1;i<=n;i++)
        if (dis[a][b]==dis[a][i]+dis[i][b])
        {
            vis[i]=true;
            if (vist[dis[a][i]]) return 0;
            vist[dis[a][i]]=true;
        }
    for (int i=1;i<=n;i++)
        d[i]=0;
    for (int i=1;i<=n;i++)
        for (int q=last[i];q;q=pre[q])
        {
            int v=other[q];
            if (dis[a][v]==dis[a][i]-1&&dis[a][v]-dis[v][b]==dis[a][i]-dis[i][b]) ++d[i];
        }
    int res=1;
    for (int i=1;i<=n;i++)
        if (!vis[i]) res=(1LL*res*d[i])%modp;
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j) dis[i][j]=707; else dis[i][j]=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        insert(a[i],b[i]),insert(b[i],a[i]);
        dis[a[i]][b[i]]=1;
        dis[b[i]][a[i]]=1;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++)
            ans[i][j]=ans[j][i]=calc(i,j);
    for (int i=1;i<=n;i++)
        ans[i][i]=deal(i);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
#include <bits/stdc++.h>
#define modp 998244353
using namespace std;
#define Maxn 3607
bool flag[Maxn][Maxn];
bool vis1[Maxn],vis2[Maxn];
int f[Maxn][Maxn],g[Maxn][Maxn],c[Maxn][Maxn];
int pre[Maxn];
int cnt1,cnt2;
int n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    c[0][0]=1;
    for (int i=1;i<=n||i<=m;i++)
    {
        c[i][0]=1;
        for (int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%modp;
    }
    pre[0]=1;
    for (int i=1;i<=n||i<=m;i++)
        pre[i]=(1LL*pre[i-1]*i)%modp;
    memset(flag,true,sizeof(flag));
    while (k--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        flag[a][b]=false;
        flag[c][d]=false;
    }
    cnt1=0;
    f[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        vis1[i]=true;
        for (int j=1;j<=m;j++)
            vis1[i]&=flag[i][j];
        if (vis1[i]) ++cnt1;
        for (int j=0;j<=n;j++)
            f[i][j]=f[i-1][j];
        if (vis1[i]&&vis1[i-1])
        {
            for (int j=1;j<=n;j++)
                f[i][j]=(f[i][j]+f[i-2][j-1])%modp;
        }
    }
    cnt2=0;
    g[0][0]=1;
    for (int i=1;i<=m;i++)
    {
        vis2[i]=true;
        for (int j=1;j<=n;j++)
            vis2[i]&=flag[j][i];
        if (vis2[i]) ++cnt2;
        for (int j=0;j<=m;j++)
            g[i][j]=g[i-1][j];
        if (vis2[i]&&vis2[i-1])
        {
            for (int j=1;j<=m;j++)
                g[i][j]=(g[i][j]+g[i-2][j-1])%modp;
        }
    }
    int ans=0;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++)
            if (2*i+j<=cnt1&&i+2*j<=cnt2)
            {
                int tmp=(1LL*c[cnt1-2*i][j]*c[cnt2-2*j][i])%modp;
                tmp=(1LL*tmp*f[n][i])%modp;
                tmp=(1LL*tmp*g[m][j])%modp;
                tmp=(1LL*tmp*pre[i])%modp;
                tmp=(1LL*tmp*pre[j])%modp;
                ans=(ans+tmp)%modp;
            }
    printf("%d\n",ans);
    return 0;
}
#include <bits/stdc++.h>
#define modp 998244353
#define Maxn 1007
using namespace std;
int n,k;
int a[Maxn];
int f[Maxn][Maxn],g[Maxn][Maxn];
int calc(int val)
{
    for (int i=0;i<=n;i++)
        for (int j=0;j<=k;j++)
            f[i][j]=0,g[i][j]=0;
    for (int i=1;i<=n;i++)
        f[i][1]=1,g[i][1]=i;
    for (int j=2;j<=k;j++)
    {
        int now=0;
        for (int i=1;i<=n;i++)
        {
            ++now;
            while (a[now]<=a[i]-val) ++now;
            --now;
            f[i][j]=(f[i][j]+g[now][j-1])%modp;
            g[i][j]=(g[i-1][j]+f[i][j])%modp;
        }
    }
    int res=0;
    for (int i=k;i<=n;i++)
        res=(res+f[i][k])%modp;
    return res;
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    for (int i=1;i<=100000/(k-1);i++)
        ans=(ans+calc(i))%modp;
    printf("%d\n",ans);
    return 0;
}
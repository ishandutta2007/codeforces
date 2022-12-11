#include <bits/stdc++.h>
#define Maxn 5007
#define inf 1000000000000000000LL
using namespace std;
int T,n;
pair<int,int> p[Maxn];
long long f[Maxn][Maxn];
void solve()
{
    scanf("%d",&n);
    memset(p,0,sizeof(p));
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].first,&p[i].second);
        p[i].first=-p[i].first;
    }
    sort(p+1,p+n+1);
    for (int i=1;i<=n;i++)
        p[i].first=-p[i].first;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            f[i][j]=inf;
    f[0][0]=0LL;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
        {
            if (j>0) f[i][j]=f[i-1][j-1]+p[i].second;
            if (n-i+j>=p[i].first) f[i][j]=min(f[i][j],f[i-1][j]);
        }
    long long ans=inf;
    for (int i=0;i<=n;i++)
        ans=min(ans,f[n][i]);
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}
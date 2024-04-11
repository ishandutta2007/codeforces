#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)

const int maxn = 1005;
const int mod = 998244353;
int a[maxn];
ll ans[100005];
int dp[maxn][maxn],sum[maxn][maxn],l[maxn];
int n,k;
int solve(int x)
{
    for(int i=0;i<=n;++i) for(int j=0;j<=k;++j) dp[i][j]=0;
    l[0]=0;
    for(int i=1;i<=n;++i)
    {
        l[i]=l[i-1];
        while(a[i]-a[l[i]+1]>=x) l[i]++;
    }
    dp[0][0]=sum[0][0]=1;
    for(int i=0;i<=k;++i)
    {
        if(i) for(int j=1;j<=n;++j) dp[i][j]=sum[i-1][l[j]];
        for(int j=1;j<=n;++j) sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
    }
    return sum[k][n];
}
int main()
{
    cin>>n>>k;
    forii cin>>a[i];
    sort(a+1,a+1+n);
    int mx=-1;
    forii mx=max(mx,a[i]);
    for(int i=1;i<=mx/(k-1);++i) ans[i]=solve(i);
    ll res=0;
    for(int i=1;i<=mx/(k-1);++i) (res+=(ans[i]-ans[i+1])*i%mod)%=mod;
    if(res<0) res+=mod;
    cout<<res<<endl;
}
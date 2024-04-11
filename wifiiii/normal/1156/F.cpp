
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 5005;

ll dp[maxn][maxn];
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
void init()
{
    f[0] = 1;
    for(int i=1;i<maxn;++i) f[i]=i*f[i-1]%mod,rf[i]=fpow(f[i],mod-2);
}
ll c[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int n;cin>>n;
    for(int i=1;i<=n;++i) {int tmp;cin>>tmp;c[tmp]++;}
    dp[0][0] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            dp[i][j] = dp[i-1][j];
            if(j) dp[i][j] = (dp[i][j] + dp[i-1][j-1] * c[i]) % mod;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        if(c[i]<2) continue;
        for(int j=1;j<=n-1;++j)
        {
            ans += dp[i-1][j-1] * c[i] * (c[i]-1) % mod * f[n-j-1] % mod;
        }
    }
    ans = ans % mod * rf[n] % mod;
    cout << ans << endl;
}
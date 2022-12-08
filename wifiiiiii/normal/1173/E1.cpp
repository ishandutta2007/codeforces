

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)
#define int ll
const int mod = 998244353;
ll w0,w1;
ll a[200005],b[200005];
ll dp[3005][3005];
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
ll ans[200005];
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) if(a[i]) w1+=b[i];else w0+=b[i];
    dp[0][0] = 1;
    for(int i=0;i<=m;++i)
    {
        for(int j=0;j<=m;++j)
        {
            dp[i][j] += (w1+i-1) * fpow(w0+w1+i-1-j, mod-2) % mod * dp[i-1][j] % mod;
            dp[i][j] += (w0-j+1) * fpow(w0+w1+i-j+1, mod-2) % mod * dp[i][j-1] % mod;
            while(dp[i][j] > mod) dp[i][j] -= mod;
        }
    }
    ll a0 = 0, a1 = 0;
    for(ll i=0;i<=m;++i)
    {
        a0 += (m-i) * dp[i][m-i] % mod;
        a1 += i * dp[i][m-i] % mod;
        if(a0 > mod) a0 -= mod;
        if(a1 > mod) a1 -= mod;
    }
    rep(i,n)
    {
        if(a[i]) ans[i] = b[i] + a1 * b[i] % mod * fpow(w1, mod-2) % mod;
        else ans[i] = b[i] - a0 * b[i] % mod * fpow(w0, mod-2) % mod;
        ans[i] %= mod;
        if(ans[i]<0) ans[i]+=mod;
        cout<<ans[i]<<endl;
    }
}
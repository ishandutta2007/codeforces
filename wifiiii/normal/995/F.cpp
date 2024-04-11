#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

vector<int> g[100005];
ll dp[3005][3005],inv[5555];
const int mod = 1e9+7;
int n,d;
void dfs(int u)
{
    for(int i=1;i<=n;++i) dp[u][i]=1;
    for(int v:g[u])
    {
        dfs(v);
        for(int i=1;i<=n;++i) dp[u][i]=dp[u][i]*dp[v][i]%mod;
    }
    for(int i=1;i<=n;++i) dp[u][i]=(dp[u][i]+dp[u][i-1])%mod;
}
const int maxn = 3005;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init()
{
    f[0] = 1;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod;
    rf[maxn-1] = fpow(f[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
ll comb2(ll n,ll k)
{
    ll ret=1;
    for(ll i=n;i>=n-k+1;--i) ret=ret*i%mod;
    for(ll i=1;i<=k;++i) ret=ret*inv[i]%mod;
    return ret;
}
ll dp2[3005];
int main()
{
    init();
    inv[1]=1;
    for(int i=2;i<=4005;++i) inv[i]=(mod-(mod/i))*inv[mod%i]%mod;
    cin>>n>>d;
    for(int i=2;i<=n;++i)
    {
        int p;
        cin >>p;
        g[p].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;++i)
    {
        dp2[i] = dp[1][i];
        for(int j=1;j<=i;++j) dp2[i] -= dp2[i-j] * comb(i,j) % mod;
        dp2[i] %= mod;
        if(dp2[i] < 0) dp2[i] += mod;
    }
    ll ans = 0;
    for(int i=1;i<=n;++i) ans += comb2(d,i) * dp2[i] % mod;
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}
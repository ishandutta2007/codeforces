#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int mod = 998244353;
const int maxn = 5005;
ll x[maxn],y[maxn];
ll comb[maxn][maxn];
void init()
{
    for(int i=0;i<maxn;++i) comb[i][0] = 1;
    for(int i=1;i<maxn;++i)
        for(int j=1;j<=i;++j)
        {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            if(comb[i][j] > mod) comb[i][j] -= mod;
        }
}
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
ll pw[maxn],rpw[maxn],pk[maxn];
int main()
{
    init();
    int n,m,k;
    cin>>n>>m>>k;
    ll prob = fpow(m, mod-2);
    pw[0] = 1; rpw[0] = 1;
    for(int i=1;i<=k+1;++i) pw[i]=pw[i-1]*prob%mod;
    for(int i=1;i<=k+1;++i) rpw[i]=rpw[i-1]*(mod+1-prob)%mod;
    for(int i=1;i<=k+1;++i) pk[i]=fpow(i,k);
    for(int i=1;i<=k+1;++i)
    {
        x[i] = i;
        ll tmp = 0;
        for(int j=1;j<=i;++j)
            tmp += comb[i][j]*pw[j]%mod*rpw[i-j]%mod*pk[j]%mod;
        tmp %= mod;
        if(tmp < 0) tmp += mod;
        y[i] = tmp;
    }
    ll ans = 0;
    for(int i=1;i<=k+1;++i)
    {
        ll tmp = y[i], tmp2 = 1;
        for(int j=1;j<=k+1;++j)
            if(i!=j)
                tmp = tmp * (n - x[j]) % mod,
                tmp2 = tmp2 * (x[i] - x[j]) % mod;
        tmp2 = fpow(tmp2, mod-2);
        ans += tmp * tmp2 % mod;
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}
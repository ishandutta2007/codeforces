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

const int maxn = 200005;
const int mod = 998244353;
ll f[maxn],rf[maxn],pw[maxn];;
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init()
{
    f[0] = pw[0] = 1;
    for(int i=1;i<maxn;++i) pw[i] = pw[i-1] * 2 % mod;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod;
    rf[maxn-1] = fpow(f[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
int main()
{
    init();
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i=n-1;i<=m;++i)
        ans += comb(i-1, n-2) * (n-2) % mod * pw[n-3] % mod;
    cout << ans % mod << endl;
}


// tp
// choose n-2 number from 1 ~ tp-1 : comb[tp-1][n-2]
// 2 equal number : n-2
//  n-3 numbers into two parts: 2 ^ (n-3)
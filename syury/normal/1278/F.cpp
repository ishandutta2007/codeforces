//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)5e3 + 3;
const ll mod = 998244353;

ll pw(ll x, ll k){
    ll res = 1;
    while(k){
        if(k&1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    ret res;
}

int n, m, k;
ll fac[N], ifac[N];
ll mgf[N], mgf2[N];

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fac[0] = ifac[0] = 1;
    F(i, 1, N){
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = ifac[i - 1] * pw(i, mod - 2) % mod;
    }
    cin >> n >> m >> k;
    if(n < N){
        ll ans = 0;
        for(int x = 0; x <= n; x++){
            ll curr = pw(x, k);
            curr *= fac[n] * ifac[x] % mod * ifac[n - x] % mod;
            curr %= mod;
            curr *= pw(m - 1, n - x);
            ans += curr%mod;
        }
        ans = ans%mod * pw(pw(m, mod - 2), n) % mod;
        cout << ans << endl;
        ret 0;
    }
    ll p = pw(m, mod - 2), q = 1 - p;
    mgf[0] = 1;
    F(iter, 0, k){
        memset(mgf2, 0, sizeof(mgf2));
        E(i, 0, iter){
            ll cc = (n - i) * 1ll * p % mod;
            mgf2[i + 1] += cc * mgf[i] % mod;
            mgf2[i] += mgf[i] * i % mod;
        }
        E(i, 0, iter+1)
            mgf2[i] %= mod;
        memcpy(mgf, mgf2, sizeof(mgf));
    }
    ll ans = 0;
    F(i, 0, N)
        ans += mgf[i];
    cout << ans%mod << endl;
    return 0;
}
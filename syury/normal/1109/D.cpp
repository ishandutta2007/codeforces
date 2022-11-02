//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e6 + 6;
const int mod = (int)1e9 + 7;

inline int pw(int x, int p){
    int res = 1;
    while(p){
        if(p&1)
            res = res * 1ll * x % mod;
        x = x * 1ll * x % mod;
        p >>= 1;
    }
    return res;
}

int fac[N], ifac[N];
int n;

inline int C(int n, int k){
    if(n < k)
        return 0;
    return fac[n] * (ifac[k] * 1ll * ifac[n - k] % mod) % mod;
}

inline int A(int n, int k){
    if(n < k)
        return 0;
    return fac[n] * 1ll * ifac[n - k] % mod;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fac[0] = ifac[0] = 1;
    for(int i = 1; i < N; i++){
        fac[i] = fac[i - 1] * 1ll * i % mod;
        ifac[i] = ifac[i - 1] * 1ll * pw(i, mod - 2) % mod;
    }
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    ll ans = 0;
    for(int r = 0; r <= n - 2; r++){
        ll curr = (r ? pw(n, r - 1) : pw(n, mod - 2)) * 1ll * (n - r) % mod;
        curr = curr * 1ll * A(n - 2, n - 2 - r) % mod;
        curr = curr * 1ll * C(m - 1, n - r - 2) % mod;
        curr = curr * 1ll * pw(m, r) % mod;
        ans += curr;
    }
    cout << ans%mod << endl;
    return 0;
}
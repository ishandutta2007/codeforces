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

const int N = (int)2e5 + 5;
const int mod = (int)1e9 + 7;

ll inv(ll x){
    ll res = 1, pw = mod - 2;
    while(pw){
        if(pw&1)res = res * x % mod;
        x = x * x % mod;
        pw >>= 1;
    }
    return res;
}

int n;
int p[N];
int l[N], r[N];
int E[N], D[N];

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", l + i);
    for(int i = 0; i < n; i++)
        scanf("%d", r + i);
    for(int i = 0; i < n - 1; i++){
        int L = r[i] - l[i] + 1, R = r[i + 1] - l[i + 1] + 1;
        int inter = max(0, min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1);
        ll Q = L * 1ll * R % mod;
        p[i] = (Q - inter) * inv(Q) % mod;
        p[i] += p[i] < 0 ? mod : 0;
    }
    p[n - 1] = 1;
    ll totalD = 0, totalE = 0;
    for(int i = 0; i < n; i++){
        totalE += p[i];
        totalD += p[i] * 1ll * (mod + 1 - p[i]) % mod;
    }
    for(int i = 0; i < n - 2; i++){
        ll cov = 0;
        ll inter3 = max(0, min({r[i], r[i + 1], r[i + 2]}) - max({l[i], l[i + 1], l[i + 2]}) + 1);
        ll lint = max(0, min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1);
        ll rint = max(0, min(r[i + 1], r[i + 2]) - max(l[i + 1], l[i + 2]) + 1);
        ll bad = lint * (r[i + 2] - l[i + 2] + 1) % mod + rint * (r[i] - l[i] + 1) % mod - inter3;
        ll Q = (r[i] - l[i] + 1) * 1ll * (r[i + 1] - l[i + 1] + 1) % mod * (r[i + 2] - l[i + 2] + 1) % mod;
        cov = (Q - bad) * inv(Q) % mod;
        cov -= p[i] * 1ll * p[i + 1] % mod;
        totalD += 2 * cov;
    }
    totalE %= mod;
    totalD %= mod;
    ll ans = totalD + totalE * totalE % mod;
    ans = (ans%mod + mod)%mod;
    printf("%lld\n", ans);
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    T = 1;
    while(T--)
        solve();
    return 0;
}
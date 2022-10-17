//
// Created by yamunaku on 2021/05/30.
//

#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

ll modpow(ll x, ll a) {
    ll ans = 1;
    while (a) {
        if (a & 1) ans = ans * x % MOD;
        a >>= 1;
        x = x * x % MOD;
    }
    return ans;
}

ll inv(ll x) {
    return modpow(x, MOD - 2);
}

vector<ll> fact, invfact;

void buildFact(int n) {
    fact = vector<ll>(n + 1, 1);
    invfact = vector<ll>(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = inv(fact[i]);
    }
}

ll comb(ll n, ll k) {
    if (n - k < 0) return 0;
    return fact[n] * invfact[n - k] % MOD * invfact[k] % MOD;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n + 1);
    repl(i, 1, n + 1) {
        a[i] = comb(n - (k - 1) * (i - 1), i);
    }
    ll ans = 0;
    repl(i, 1, n) {
        ans = (ans +
               (i + 1) * (((n - i) * a[i] - (i + 1) * a[i + 1]) % MOD) % MOD * fact[i] % MOD * invfact[n] % MOD *
               fact[n - i - 1]) %
              MOD;
    }
    cout << ans << endl;
}

int main() {
    CFS;
    int t;
    cin >> t;
    buildFact(100000);
    rep(i, t) solve();
    return 0;
}
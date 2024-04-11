//
// Created by yamunaku on 2020/12/30.
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

void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    vl one(60), zero(60);
    rep(k, 60) {
        rep(i, n) {
            if (a[i] & (1ll << k)) one[k]++;
            else zero[k]++;
        }
    }
    ll ans = 0;
    rep(i, n) {
        ll tmp1 = 0, tmp2 = 0;
        rep(k, 60) {
            if (a[i] & (1ll << k)) {
                tmp1 += (1ll << k) % MOD * one[k] % MOD;
                tmp2 += (1ll << k) % MOD * n % MOD;
            } else {
                tmp2 += (1ll << k) % MOD * one[k] % MOD;
            }
        }
        tmp1 %= MOD, tmp2 %= MOD;
        ans = (ans + tmp1 * tmp2) % MOD;
    }
    cout << ans << endl;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}
//
// Created by yamunaku on 2021/02/28.
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
#define MOD1 1000000007
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
    ll n, u, v;
    cin >> n >> u >> v;
    vi a(n);
    rep(i, n) cin >> a[i];
    bool ok = false;
    rep(i, n - 1) {
        int k = abs(a[i] - a[i + 1]);
        if (k >= 2) {
            cout << 0 << endl;
            return;
        }
        if (k == 1) ok = true;
    }
    if (ok) {
        cout << min(u, v) << endl;
    } else {
        cout << v + min(u, v) << endl;
    }
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}
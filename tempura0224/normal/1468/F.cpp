//
// Created by yamunaku on 2020/12/25.
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

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    while (x % y) {
        ll tmp = x % y;
        x = y;
        y = tmp;
    }
    return y;
}

void solve() {
    int n;
    cin >> n;
    map<pair<ll, ll>, ll> mp;
    rep(i, n) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll x = x2 - x1;
        ll y = y2 - y1;
        ll g;
        if (x >= 0) {
            if (y >= 0) g = gcd(x, y);
            else g = gcd(x, -y);
        } else {
            if (y >= 0) g = gcd(-x, y);
            else g = gcd(-x, -y);
        }
        x /= g;
        y /= g;
        mp[{x, y}]++;
    }
    ll ans = 0;
    for (auto &p : mp) {
        auto v = p.first;
        auto itr = mp.find({-v.first, -v.second});
        if (itr == mp.end()) continue;
        ans += p.second * itr->second;
    }
    cout << ans / 2 << endl;
}

int main() {
    //CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}
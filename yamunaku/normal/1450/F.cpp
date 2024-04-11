//
// Created by yamunaku on 2020/12/06.
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
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i], a[i]--;
    vector<pair<int, pair<int, int>>> c(n);
    rep(i, n) c[i] = {0, {i, 0}};
    int ans = 0;
    int pre = a[0];
    rep(i, n - 1) {
        if (a[i] == a[i + 1]) {
            ans++;
            if (pre == a[i]) {
                c[a[i]].first++;
            } else {
                c[pre].second.second++;
                c[a[i]].second.second++;
            }
            pre = a[i];
        }
    }
    if (pre == a[n - 1]) {
        c[a[n - 1]].first++;
    } else {
        c[pre].second.second++;
        c[a[n - 1]].second.second++;
    }
//    rep(i, n) {
//        cout << c[i].second.first SP c[i].first SP c[i].second.second << endl;
//    }
    sort(all(c), greater<pair<int, pair<int, int>>>());
    if (c[0].first <= ans + 1 - c[0].first - c[0].second.second + 1) {
        cout << ans << endl;
        return;
    }
    int can = 0;
    rep(i, n - 1) {
        if (a[i] != a[i + 1] && a[i] != c[0].second.first && a[i + 1] != c[0].second.first) {
            can++;
        }
    }
    if (c[0].first <= ans + 1 - c[0].first - c[0].second.second + 1 + can)
        cout << ans + c[0].first - (ans + 1 - c[0].first - c[0].second.second + 1) << endl;
    else cout << -1 << endl;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}
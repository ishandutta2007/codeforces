#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//using ii = __int128;

using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

const int INF = 1e9+7;
const ll LINF = 1e18;

mt19937 rng;

bool solve(vi& p) {
    int n; cin >> n;
    p.resize(n);
    vpi v, u;
    for(int i = 0, j = 0, h = 0; i < 2*n; ++i) {
        string s; cin >> s;
        if(s[0] == '+') ++j, ++h;
        else {
            int x; cin >> x;
            v.eb(x, j), u.eb(x, j), --h;
            if(h < 0) return false;
        }
    }
    set<int> s;
    for(int i = 0; i < n; ++i) s.insert(i);
    sort(all(v));
    for(auto [x, i] : v) {
        auto it = s.lower_bound(i);
        if(it == s.begin()) return false;
        it = prev(it);
        p[*it] = x;
        s.erase(it);
    }

    set<int> y;
    for(int i = 0, j = 0; i < n; ++i) {
        while(j < u[i].S) y.insert(p[j++]);
        const int x = *(y.begin()); y.erase(y.begin());
        if(x != u[i].F) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    //int t; cin >> t; while(t--) solve();
    vi p;
    if(solve(p)) {
        cout << "YES" << endl;
        for(int i : p) cout << i << ' ';
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
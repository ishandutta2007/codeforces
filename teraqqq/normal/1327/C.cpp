#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp>
#include <stdint.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rsz resize
#define mp make_pair

#define sz(x) ((int)(x).size())
#define all(x)  (x).begin(),  (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

using ld = double;
using cd = complex<ld>;
using vcd = vector<cd>;

template<class T> using ordered_set = tree<T, null_type, less<T>,
                         rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const int INF = 1e9;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vpi v(k); for(pi& x : v) cin >> x.F >> x.S;

    string res;
    for(int i = n; --i; ) res.pb('U');
    for(int j = m; --j; ) res.pb('L');

    for(int i = 0; i < n; ) {
        for(int j = m; --j; )
            res.pb(i % 2 ? 'L' : 'R');
        if(++i < n) res.pb('D');
    }

    if(res.empty()) res.pb('U');
    if(sz(res) > 2*n*m) cout << -1 << endl;
    else cout << sz(res) << endl << res << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--) solve();
}
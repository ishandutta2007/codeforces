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
const int MOD = 998244353;
const int N = 1e5+7;

int a[N], b[N], rt, res;
set<pi> sss;
vi g[N];

void dfs_a(int v, int p = -1) {
    if(sz(g[v]) == 1) return;
    for(int to : g[v])
        if(to != p) dfs_a(to, v), ckmax(a[v], 1 - a[to]), sss.emplace(b[v], b[to]);
    for(int to : g[v])
        if(to != p) ckmax(res, a[v] + a[to]);
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a-1].pb(b-1), g[b-1].pb(a-1);
    }

    for(int i = 0, k = 0; i < n; ++i)
        if(sz(g[i]) > 1) rt = i, b[i] = ++k;
    dfs_a(rt);

    cout << max(1, res*(res+1)/2) << ' ' << sz(sss) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
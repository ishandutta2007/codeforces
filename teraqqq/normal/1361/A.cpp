#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rsz resize
#define mp make_pair

#define BK back()
#define FR front()

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = double;

using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = atan((ld)1)*4;

mt19937 rng;

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> g(n);
    while(m--) {
        int a, b; cin >> a >> b;
        g[a-1].pb(b-1), g[b-1].pb(a-1);
    }
    vpi t(n);
    for(int i = 0; i < n; t[i].S = i, ++i) cin >> t[i].F;
    sort(t.begin(), t.end());

    vi mam(n+1), val(n);
    bool ok = true;
    for(pi x : t) {
        const int v = x.S, w = x.F;
        for(int to : g[v]) mam[val[to]]++;
        for(val[v] = 1; mam[val[v]]; ++val[v]);
        for(int to : g[v]) mam[val[to]]--;
        if(val[v] != w) ok = false;
    }

    if(ok)
        for(pi i : t) cout << i.S+1 << ' ';
    else cout << -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    //int t; cin >> t;
    int t = 1;
    while(t--) solve();
}
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int MOD = 1e9+7;

mt19937 rng;

vi G[1148576];
vpi g[1148576];
map<pi, vi> KEK;
bool u[1148576], us[1148576];

ll sgn(ll x) { return x ? x < 0 ? -1 : 1 : 0; }

int get_graph(const int n, const vi& a, int k) {
    for(int i = 0; i < 1148576; ++i) G[i].rsz(0);
    for(int i = 0; i < n; ++i) {
        G[a[2*i+0]&(1<<k)-1].pb(a[2*i+1]&(1<<k)-1);
        G[a[2*i+1]&(1<<k)-1].pb(a[2*i+0]&(1<<k)-1);
    }
    int SZ = 0;
    for(int i = 0; i < 1148576; ++i) if(!G[i].empty()) ++SZ;
    return SZ;
}

int dfs(int v) {
    u[v] = 1; int res = 1;
    for(int to : G[v]) if(!u[to]) res += dfs(to);
    return res;
}

bool check(int SZ) {
    int v0 = -1;
    for(int i = 0; i < 1148576; ++i) {
        if(sz(G[i])) v0 = i; u[i] = 0;
        if(sz(G[i]) % 2) { return false; }
    }
    int res = dfs(v0);
    return res == SZ;
}

void solve() {
    int n; cin >> n;
    vi a(2*n); for(int& x : a) cin >> x;

    int L = 0, R = 20;
    while(L < R) {
        int M = L + R + 1 >> 1;
        auto g = get_graph(n, a, M);
        if(check(g)) L = M;
        else R = M - 1;
    }

    for(int i = 0; i < n; i++) {
        KEK[mp(a[2*i+0]&(1<<R)-1, a[2*i+1]&(1<<R)-1)].pb(2*i);
        KEK[mp(a[2*i+1]&(1<<R)-1, a[2*i+0]&(1<<R)-1)].pb(2*i+1);
    }

    vi st, ans, a2;
    for(int i = 0; i < n; ++i) {
        g[a[2*i+0]&(1<<R)-1].eb(a[2*i+1]&(1<<R)-1, i);
        g[a[2*i+1]&(1<<R)-1].eb(a[2*i+0]&(1<<R)-1, i);
        if(st.empty()) st.pb(a[2*i+0]&(1<<R)-1);
    }

    while(!st.empty()) {
        int v = st.back();
        //cout << v << endl;
        while(!g[v].empty() && us[g[v].back().S]) g[v].pop_back();
        if(g[v].empty()) ans.pb(v), st.pop_back();
        else {
            pi edge = g[v].back(); us[edge.S] = 1;
            st.push_back(edge.F);
        }
    }

    //ans.pb(ans.front());
    for(int i = 1; i < ans.size(); ++i) {
        //cout << ans[i] << "!" << endl;
        while(!us[KEK[mp(ans[i-1], ans[i])].back()/2]) KEK[mp(ans[i-1], ans[i])].pop_back();
        const int j = KEK[mp(ans[i-1], ans[i])].back(); us[j/2] = 0;
        a2.pb(j), a2.pb(j^1);
    }

    cout << R << endl;
    for(int i : a2) cout << i+1 << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    //int t; cin >> t;
    int t = 1;
    while(t--) solve();
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld PI = acos(-1);

const int N = 1e5 + 10;
const int LOG = 20;
vector<vector<int> > g;
int level[N], parent[N], ans[N], tin[N], tout[N], timer, up[N][LOG], h[N];

void dfs(int v, int p, int cur_h = 0) {
    up[v][0] = p;
    h[v] = cur_h;
    timer++;
    tin[v] = timer;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v, cur_h + 1);
        }
    }
    timer++;
    tout[v] = timer;
}

void build_sparse(int n) {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

_ bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

_ int lca(int u, int v) {
    if (ancestor(u, v)) {
        return u;
    }
    if (ancestor(v, u)) {
        return v;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[v][i] && !ancestor(up[v][i], u)) {
            v = up[v][i];
        }
    }
    return up[v][0];
}

_ int get_dist(int u, int v) {
    int w = lca(u, v);
    return h[u] + h[v] - 2 * h[w];
}

int find_centroid(int v, int &centroid, int sum, int parent = 0) {
    int sz = 1;
    for (auto u : g[v]) {
        if (u != parent && !level[u]) {
            sz += find_centroid(u, centroid, sum, v);
        }
    }
    if (!centroid && (!parent || 2 * sz >= sum)) {
        centroid = v;
    }
    return sz;
}

void solve(int v, int cur_level, int sum, int from = 0) {
    int cur = 0;
    find_centroid(v, cur, sum);
    level[cur] = cur_level;
    parent[cur] = from;
    for (auto u : g[cur]) {
        if (!level[u]) {
            solve(u, cur_level + 1, sum / 2, cur);
        }
    }
}

_ void add_red(int v) {
    int start = v;
    while (v) {
        ans[v] = min(ans[v], get_dist(start, v));
        v = parent[v];
    }
}

_ int get_min(int v) {
    int res = INF, start = v;
    while (v) {
        res = min(res, ans[v] + get_dist(start, v));
        v = parent[v];
    }
    assert(res < INF);
    return res;
}

_ void source() {
    int n, m;
    cin >> n >> m;
    g.rsz(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    build_sparse(n);
    solve(1, 1, n);
    for (int i = 1; i <= n; i++) {
        ans[i] = INF;
    }
    add_red(1);
    for (int i = 1; i <= m; i++) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            add_red(v);
        }
        else {
            cout << get_min(v) << '\n';
        }
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}
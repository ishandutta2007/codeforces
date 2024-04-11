//I_l_M_P
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

const int N = 3e5 + 10;
vector<vector<int> > g, ng;
set<pair<int, int> > bridges;
int tin[N], up[N], h[N], c[N], timer;
bool used[N];

void find_bridges(int v, int parent = 0) {
    timer++;
    tin[v] = up[v] = timer;
    used[v] = true;
    for (auto u : g[v]) {
        if (u != parent) {
            if (!used[u]) {
                find_bridges(u, v);
                if (up[u] > tin[v]) {
                    bridges.ins({u, v});
                    bridges.ins({v, u});
                }
                up[v] = min(up[v], up[u]);
            }
            else {
                up[v] = min(up[v], tin[u]);
            }
        }
    }
}

void go(int v, int color) {
    c[v] = color;
    for (auto u : g[v]) {
        if (!c[u] && bridges.find({u, v}) == bridges.end()) {
            go(u, color);
        }
    }
}

void dfs(int v, int cur_h) {
    h[v] = cur_h;
    used[v] = true;
    for (auto u : ng[v]) {
        if (!used[u]) {
            dfs(u, cur_h + 1);
        }
    }
}

_ void source() {
    int n, m;
    cin >> n >> m;
    g.rsz(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    find_bridges(1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!c[i]) {
            cnt++;
            go(i, cnt);
        }
    }
    ng.rsz(cnt + 1);
    for (auto it : bridges) {
        ng[c[it.f]].pb(c[it.sec]);
        ng[c[it.sec]].pb(c[it.f]);
    }
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    dfs(1, 0);
    pair<int, int> mx = {-INF, -INF};
    for (int i = 1; i <= cnt; i++) {
        mx = max(mx, {h[i], i});
    }
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    dfs(mx.sec, 0);
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans = max(ans, h[i]);
    }
    cout << ans;
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
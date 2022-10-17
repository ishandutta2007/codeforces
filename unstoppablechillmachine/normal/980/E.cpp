#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

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

const int LOG = 21;
const int N = 1e6 + 10;
vector<vector<int> > g;
int up[N][LOG];
bool was[N];

void dfs(int v, int p) {
    up[v][0] = p;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
}

_ int get_dist(int v) {
    int cur = v, res = 1;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[cur][i] && !was[up[cur][i]]) {
            res += 1 << i;
            cur = up[cur][i];
        }
    }
    return res;
}

_ void source() {
    int n, k;
    cin >> n >> k;
    k = n - k - 1;
    g.rsz(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(n, 0);
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    was[n] = true;
    for (int i = n - 1; k > 0; i--) {
        if (was[i]) {
            continue;
        }
        int a = get_dist(i);
        if (a <= k) {
            k -= a;
            a = i;
            while (!was[a]) {
                was[a] = true;
                a = up[a][0];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!was[i]) {
            cout << i << ' ';
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
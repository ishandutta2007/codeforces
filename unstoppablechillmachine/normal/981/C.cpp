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
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 100003;
const long long BINF = 1e18 + 10;

vector<vector<int> > g;
vector<pair<int, int> > ans;

void dfs(int v, int from_v, int p, bool was) {
    int cnt = g[v].size();
    if (p) {
        cnt--;
    }
    if (!cnt) {
        ans.pb({from_v, v});
        return;
    }
    if (cnt == 1) {
        if (g[v][0] != p) dfs(g[v][0], from_v, v, was);
        else dfs(g[v][1], from_v, v, was);
        return;
    }
    if (was) {
        cout << "No";
        exit(0);
    }
    bool t = false;
    for (auto u : g[v]) {
        if (u == p) {
            continue;
        }
        if (!t) {
            dfs(u, from_v, v, true);
            t = true;
        }
        else {
            dfs(u, v, v, true);
        }
    }
}

_ void source() {
    int n, root;
    cin >> n;
    g.rsz(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            root = i;
        }
    }
    dfs(root, root, 0, false);
    cout << "Yes" << endl << ans.size() << endl;
    for (auto it : ans) {
        cout << it.f << ' ' << it.sec << endl;
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
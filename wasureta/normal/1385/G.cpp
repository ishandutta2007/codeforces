// g-columns-swaps.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define pb push_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct Ed {
    int v, inv;
};

const int MN = 2e5 + 1;
int N,
    val[2][MN];
vector<Ed> g[MN];

// dfs
int clr[MN];
vector<int> zero, one;
bool bad = false;

void dfs(int c, int cclr) {
    if (bad) return;
    if (clr[c] != -1) {
        if (cclr != clr[c])
            bad = true;
        return;
    }

    clr[c] = cclr;
    if (cclr) one.pb(c);
    else zero.pb(c);
    for (auto to : g[c])
        dfs(to.v, cclr ^ to.inv);
}

void solve() {
    vector<vector<pii>> pos(N + 1);
    for (auto i = 0; i < 2; i++)
        for (auto j = 1; j <= N; j++)
            pos[val[i][j]].emplace_back(j, i);
    for (auto i = 1; i <= N; i++) {
        if (SZ(pos[i]) != 2) {
            cout << (-1) << '\n';
            return;
        }

        int inv = pos[i][0].second == pos[i][1].second, a = pos[i][0].first, b = pos[i][1].first;
        g[a].pb({b, inv});
        g[b].pb({a, inv});
    }

    bad = false;
    vector<int> ans;
    for (auto i = 1; i <= N; i++) {
        if (clr[i] == -1) {
            zero.clear(); one.clear();
            dfs(i, 0);
            if (SZ(zero) > SZ(one)) swap(zero, one);
            ans.insert(ans.end(), all(zero));

            if (bad) {
                cout << (-1) << '\n';
                return;
            }
        }
    }
    cout << (SZ(ans)) << '\n';
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> (N);
        for (auto i = 1; i <= N; i++)
            g[i].clear();
        fill(clr, clr + N + 1, -1);

        for (auto i = 0; i < 2; i++)
            for (auto j = 1; j <= N; j++)
                cin >> (val[i][j]);

        solve();
    }

    return 0;
}
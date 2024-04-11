// e-directing-edges.yml
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
    int v, t, i;
};

const int MN = 2e5 + 10;
int N, M,
    A[MN], B[MN], T[MN];
vector<Ed> g[MN];
bool ans[MN];

// topocheck
int indeg[MN], torder[MN];

void solve() {
    // toposort
    for (auto i = 0; i < M; i++)
        if (T[i] == 1)
            indeg[B[i]]++;
    int corder = 1;
    queue<int> q;
    for (auto i = 1; i <= N; i++)
        if (!indeg[i])
            q.push(i);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        torder[c] = corder++;
        for (auto to : g[c]) {
            if (!to.t) continue;
            indeg[to.v]--;
            if (!indeg[to.v])
                q.push(to.v);
        }
    }
    for (auto i = 1; i <= N; i++) {
        if (indeg[i]) { // cycle
            cout << ("NO") << '\n';
            return;
        }
    }

    // do dfs

    cout << ("YES") << '\n';
    for (auto i = 0; i < M; i++) {
        int a = A[i], b = B[i];
        if (!T[i] && torder[a] > torder[b]) swap(a, b);
        cout << (a) << ' ' << (b) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> (N) >> (M);
        for (auto i = 1; i <= N; i++)
            g[i].clear();
        fill(torder, torder + N + 1, -1);
        fill(indeg, indeg + N + 1, 0);
        fill(ans, ans + M + 1, false);

        for (auto i = 0; i < M; i++) {
            cin >> (T[i]) >> (A[i]) >> (B[i]);
            g[A[i]].pb({B[i], T[i], i});
        }
        solve();
    }


    return 0;
}
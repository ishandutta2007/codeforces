// f-removing-leaves.yml
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

const int MN = 2e5 + 1;
int N, K;
set<int> g[MN];

// int cnt[MN];
// void dfs(int c, int p) {
//     for (int to : g[c]) {
//         if (to != p) {
//             dfs(to, c);
//             cnt[c] += SZ(g[to]) == 1;
//         }
//     }
// }

void solve() {
    // int rt = -1;
    // for (auto i = 1; i <= N; i++) {
    //     if (SZ(g[i]) > 1) {
    //         rt = i;
    //         dfs(i, -1);
    //         break;
    //     }
    // }
    //
    if (K == 1) {
        cout << (N - 1) << '\n';
        return;
    }
    
    set<pii, greater<pii>> pq;
    vector<int> cnt(N + 1), leafTo(N + 1);
    for (auto i = 1; i <= N; i++) {
        if (SZ(g[i]) == 1) {
            leafTo[i] = *g[i].begin();
            cnt[leafTo[i]]++;
        }
    }
    for (auto i = 1; i <= N; i++) {
        pq.emplace(cnt[i], i);
    }

    int ans = 0;
    while (!pq.empty() && pq.begin()->first >= K) {
        auto c = *pq.begin(); pq.erase(pq.begin());
        vector<int> toRem;
        for (auto to : g[c.second]) {
            if (SZ(g[to]) == 1) {
                toRem.pb(to);
                if (SZ(toRem) == K)
                    break;
            }
        }

        // cout<<"c.first="<<(c.first)<<", "; cout<<"c.second="<<(c.second)<<", "; cout << "toRem=["; for (auto x:toRem)cout<<x<<", "; cout<<"], "; cout << endl; // db c.first, c.second, I:toRem

        ans++;
        for (auto x : toRem) g[c.second].erase(x);
        cnt[c.second] -= K;

        if (SZ(g[c.second]) == 1) {
            int lto = *g[c.second].begin();
            pq.erase({cnt[lto], lto});
            cnt[lto]++;
            pq.insert({cnt[lto], lto});
        }
        else {
            pq.emplace(c.first - K, c.second);
            // cout<<"c.first="<<(c.first)<<", "; cout<<"c.first-K="<<(c.first-K)<<", "; cout << endl; // db c.first, c.first-K
        }
    }

    // if (K == 1) ans++; // Increase ans by 1 since we can just remove the final node :p
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> (N) >> (K);
        for (auto i = 1; i <= N; i++)
            g[i].clear();
            
        for (auto i = 1; i < N; i++) {
            int a, b;
            cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }

        solve();
    }

    return 0;
}
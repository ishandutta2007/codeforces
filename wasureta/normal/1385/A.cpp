// a-three-pairwise-maximums.yml
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

ll a[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        for (auto i = 0; i < 3; i++)
            cin >> (a[i]);

        sort(a, a + 3);
        if (a[1] != a[2]) {
            cout << ("NO") << '\n';
        }
        else {
            cout << ("YES") << '\n';
            cout << (a[2]) << ' ' << (a[0]) << ' ' << (1) << '\n';
        }

        // ll x, y, z;
        // cin >> x >> y >> z;
        // if (x != y && y != z && x != z) {
        //     cout << ("NO") << '\n';
        // }
        // else {
        //     cout << ("YES") << '\n';
        //     if (x == z) {
        //         cout << (1) << ' ' << (x) << ' ' << (y) << '\n';
        //     }
        //     else if (x == y) {
        //         print x, 
    }

    return 0;
}
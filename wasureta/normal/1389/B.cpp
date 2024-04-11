// b-array-walk.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
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
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 10, MZ = 7;
int N, K, Z,
    val[MN], dp[MZ][MN][2];

void solve() {
    dp[0][1][0] = val[1];
    for (auto i = 0; i <= Z; i++) {
        int epos = K - i * 2;
        for (auto j = 1; j <= epos; j++) {
            for (auto k = 0; k < 2; k++) {
                if (k == 0 && j > 1)
                    maxa(dp[i + 1][j - 1][1], dp[i][j][k] + val[j - 1]);
                maxa(dp[i][j + 1][0], dp[i][j][k] + val[j + 1]);
                // if (N==10&&K==7&&Z<=3){
                //     cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"k="<<(k)<<", "; cout<<"dp[i][j][k]="<<(dp[i][j][k])<<", "; cout << endl; // db i,j,k,dp[i][j][k]
                // }
            }
        }
    }

    int ans = 0;
    for (auto i = 0; i <= Z; i++) {
        int epos = K + 1 - i * 2;
        if (epos < 0) continue;
        maxa(ans, max(dp[i][epos][0], dp[i][epos][1]));
    }
    cout << (ans) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N) >> (K) >> (Z);
        for (auto i = 1; i <= N; i++)
            cin >> (val[i]);
        for (auto i = 0; i <= Z; i++)
            for (auto j = 1; j <= N; j++)
                for (auto k = 0; k < 2; k++)
                    dp[i][j][k] = 0;

        solve();

        // Reset
    }
}
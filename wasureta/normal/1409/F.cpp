// ./f-subsequences-of-length-two.yml
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
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

/*

dp[idx][changes][occurences of t[0]]

*/

const int MN = 201;
int N, K,
    dp[MN][MN][MN], cnt[MN][2];
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (K) >> (s) >> (t);
    s = "$" + s;
    for (auto i = 1; i <= N; i++)
        for (auto j = 0; j < 2; j++)
            cnt[i][j] = cnt[i - 1][j] + (s[i] == t[j]);
    
    if (t[0] == t[1]) {
        int maxv = min(N, cnt[N][0] + K);
        // cout<<"maxv="<<(maxv)<<", "; cout << endl; // db maxv
        cout << ((maxv * (maxv - 1)) / 2) << '\n';
        return 0;
    }

    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j <= K; j++) {
            for (auto k = 0; k < N; k++) {
                for (auto l = 0; l < 2; l++) {
                    int add = k * (l == 1), inc = s[i + 1] == t[l];
                    if (j < K) { // set s[i+1] to t[l]
                        int newK = k + (l == 0);
                        maxa(dp[i + 1][j + 1][newK], dp[i][j][k] + add);
                    }
                    int newK = k + (s[i + 1] == t[0] && l == 0);
                    maxa(dp[i + 1][j][newK], dp[i][j][k] + add * inc);
                }
            }
        }
    }

    int ans = 0;
    for (auto i = 0; i <= K; i++)
        for (auto j = 0; j <= N; j++)
            maxa(ans, dp[N][i][j]);
    cout << (ans) << '\n';

    return 0;
}
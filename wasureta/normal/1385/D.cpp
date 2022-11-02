// d-a-good-string.yml
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

int let(char c) { return c - 'a'; }

const int MN = 2e5 + 1;
int N,
    dp[MN][26];
string s;

int solve(int l, int r, int clet) {
    if (l == r) return let(s[l]) != clet;
    int mid = (l + r) / 2, lcost = 0, rcost = 0;
    for (auto i = l; i <= mid; i++) lcost += let(s[i]) != clet;
    for (auto i = mid + 1; i <= r; i++) rcost += let(s[i]) != clet;
    // cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"clet="<<(clet)<<", "; cout<<"mid="<<(mid)<<", "; cout<<"lcost="<<(lcost)<<", "; cout<<"rcost="<<(rcost)<<", "; cout << endl; // db l,r,clet,mid,lcost,rcost
    int res = min(solve(l, mid, clet + 1) + rcost, solve(mid + 1, r, clet + 1) + lcost);
    // cout<<"res="<<(res)<<", "; cout << endl; // db res
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> (N) >> (s);
        int ans = solve(0, N - 1, 0);
        cout << (ans) << '\n';
    }

    return 0;
}
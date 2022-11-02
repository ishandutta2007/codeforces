// d-segment-intersections.yml
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

int N;
ll K, l1, r1, l2, r2;

void solve() {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }

    ll ans = LLINF, minInterLen = max(0LL, min(r1, r2) - max(l1, l2)), maxInterLen = max(r1, r2) - min(l1, l2) - minInterLen;
    if (r1 < l2) {
        for (auto i = 1; i <= N; i++) {
            ll cans = (l2 - r1) * i, ck = K;

            ll d = min(ck, maxInterLen * i);
            // cout<<"i="<<(i)<<", "; cout<<"cans="<<(cans)<<", "; cout<<"d="<<(d)<<", "; cout << endl; // db i,cans,d
            cans += d;
            ck -= d;
            cans += ck * 2;

            mina(ans, cans);
        }
    }
    else {
        ans = 0;
        K -= min(K, minInterLen * N);

        ll d = min(K, maxInterLen * N);
        K -= d;
        ans += d;

        ans += K * 2; // extending segments arbitrarily
    }

    cout << (ans) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N) >> (K) >> (l1) >> (r1) >> (l2) >> (r2);
        
        solve();

        // Reset
    }
}
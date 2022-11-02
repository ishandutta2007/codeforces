// e-calendar-ambiguity.yml
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

ll M, D, W;

vector<ll> factor(ll x) {
    vector<ll> res;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.pb(i);
            if (i * i != x) res.pb(x / i);
        }
    }
    sort(all(res));
    return res;
}

ll tri(ll x) { return x * (x + 1) / 2; } // 1 + 2 + ... + (x-1)

void solve() {
    // auto df = factor(D - 1);
    ll diff = __gcd(D - 1, W);

    vector<ll> df{diff};
    ll ans = 0;
    for (auto f : df) {
        if (W % f == 0) {
            ll bound = min(M, D) - 1, rem = W / f, maxMultiple = bound / rem; // mk -> rem

            // sum of arith series...
            ll first = bound - maxMultiple * rem + 1;
            // cout<<"bound="<<(bound)<<", "; cout<<"rem="<<(rem)<<", "; cout<<"maxMultiple="<<(maxMultiple)<<", "; cout<<"first="<<(first)<<", "; cout << endl; // db bound,rem,maxMultiple,first
            ans += first * maxMultiple + tri(maxMultiple - 1) * rem;
        }
    }
    cout << (ans) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (M) >> (D) >> (W);
        
        solve();

        // Reset
    }
}
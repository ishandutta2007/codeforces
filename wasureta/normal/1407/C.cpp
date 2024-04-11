// ./c-chocolate-bunny.yml
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

#ifdef LOCAL
const int nn = 5, aa[5] = {2, 3, 1, 5, 4};
int ctr=0;
int ask(int i, int j) {
    i--; j--; ctr++;
    return aa[i] % aa[j];
}
#else
int ask(int i, int j) {
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}
#endif

const int MN = 1e4 + 1;
int N,
    A[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef LOCAL
    N = nn;
#else
    cin >> (N);
#endif

    fill(A, A + N, -1);
    deque<int> rem(N); iota(all(rem), 0);
    while (SZ(rem) > 1) {
        int fs = rem.front(); rem.pop_front(); int sn = rem.front(); rem.pop_front();

        // assume a>b
        int a = ask(fs + 1, sn + 1), b = ask(sn + 1, fs + 1);
        if (a < b) {
            swap(a, b);
            swap(fs, sn);
        }

        A[fs] = a;
        rem.pb(sn);
    }
    A[rem.front()] = N;

    cout << "! ";
    for (auto i = 0; i < N; i++)
        cout << A[i] << ' ';
    cout << '\n'; cout.flush();
#ifdef LOCAL
    cout<<"ctr="<<(ctr)<<", "; cout << endl; // db ctr
#endif

    return 0;
}
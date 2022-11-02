// c-good-string.yml
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

const int MN = 2e5 + 10;
int N,
    nxt[MN][10], lst[10];
string s;

void solve() {
    for (auto i = 0; i <= N; i++)
        for (auto j = 0; j < 10; j++)
            nxt[i][j] = INF;
    memset(lst, 0x3f, sizeof lst);
    for (auto i = N-1; i >= 0; i--) {
        int c = s[i] - '0';
        lst[c] = i;
        for (auto j = 0; j < 10; j++)
            nxt[i][j] = lst[j];
    }

    int ans = N - 2;
    for (auto i = 0; i < 10; i++) {
        for (auto j = 0; j < 10; j++) {
            int cur = nxt[0][i], cnt = 0, want = 1;
            while (cur < N) {
                cnt++;
                // if (N==5){
                // cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"cur="<<(cur)<<", "; cout<<"cnt="<<(cnt)<<", "; cout<<"want="<<(want)<<", "; cout << endl; // db i,j,cur,cnt,want
                // }
                cur = nxt[cur + 1][want ? j : i];
                want ^= 1;
            }
            if (cnt % 2) cnt--;
            mina(ans, N - cnt);
        }
    }
    for (auto i = 0; i < 10; i++) {
        int cnt = 0;
        for (auto j = 0; j < N; j++) {
            int c = s[j] - '0';
            cnt += c != i;
        }
        mina(ans, cnt);
    }
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        N = SZ(s);
        solve();
    }

    return 0;
}
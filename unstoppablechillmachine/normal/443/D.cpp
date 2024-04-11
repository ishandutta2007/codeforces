#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void source() {
    int n;
    cin >> n;
    vector<ld> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }
    sort(all(arr));
    vector<ld> pref0(n + 2), pref1(n + 2), suf0(n + 2), suf1(n + 2);
    pref0[0] = 1;
    pref1[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref1[i] = pref0[i - 1] * arr[i - 1] + pref1[i - 1] * (1.0 - arr[i - 1]);
        pref0[i] = pref0[i - 1] * (1.0 - arr[i - 1]);
    }
    suf0[n + 1] = 1;
    suf1[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suf1[i] = suf0[i + 1] * arr[i - 1] + suf1[i + 1] * (1.0 - arr[i - 1]);
        suf0[i] = suf0[i + 1] * (1.0 - arr[i - 1]);
    }
    ld ans = 0;
    for (int pref_len = 0; pref_len <= n; pref_len++) {
        for (int suf_len = 0; suf_len <= n - pref_len; suf_len++) {
            if (pref_len || suf_len) {
                ans = max(ans, pref0[pref_len] * suf1[n + 1 - suf_len] + pref1[pref_len] * suf0[n + 1 - suf_len]);
            }
        }
    }
    cout << fixed << setprecision(10) << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}
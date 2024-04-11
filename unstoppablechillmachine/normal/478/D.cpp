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

const int N = 2e5 + 10;
int dp1[N], dp2[N];

_ void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

_ void source() {
    int n, m;
    cin >> n >> m;
    dp1[n] = 1;
    for (int level = 0;; level++) {
        int cur = level * (level + 1) / 2;
        for (int cnt1 = 0; cnt1 <= min(n, cur); cnt1++) {
            int c1 = n - cnt1;
            int cnt2 = m - (cur - cnt1);
            if (cnt2 < 0) {
                continue;
            }
            if (c1 >= level + 1) {
                add(dp2[c1 - level - 1], dp1[c1]);
            }
            if (cnt2 >= level + 1) {
                add(dp2[c1], dp1[c1]);
            }
        }
        bool t = false;
        for (int i = 0; i <= n; i++) {
            if (dp2[i]) {
                t = true;
                break;
            }
        }
        if (!t) {
            break;
        }
        for (int i = 0; i <= n; i++) {
            dp1[i] = dp2[i];
            dp2[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        add(ans, dp1[i]);
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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
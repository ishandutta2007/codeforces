#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
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

const int N = 3e4 + 10;
const int MX_LEN = 3050;
int16_t cnt[N], dp[N][MX_LEN + 10];
int lim;

int go(int cur, int step) {
    int mx = 0;
    for (int i = step - 1; i <= step + 1; i++) {
        if (cur + i <= lim) {
            mx = max(mx, go(cur + i, i));
        }
    }
    return mx + cnt[cur];
}

_ void source() {
    int n, start;
    cin >> n >> start;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        lim = max(lim, x);
    }
    if (start >= MX_LEN) {
        cout << go(start, start);
        exit(0);
    }
    for (int i = start; i <= lim; i++) {
        for (int j = 1; j <= MX_LEN; j++) {
            dp[i][j] = -30000;
        }
    }
    dp[start][start] = cnt[start];
    int16_t ans = 0;
    for (int i = start; i <= lim; i++) {
        for (int j = 1; j <= MX_LEN; j++) {
            ans = max(ans, dp[i][j]);
            if (i + j - 1 <= lim && j > 1) {
                dp[i + j - 1][j - 1] = max(dp[i + j - 1][j - 1], (int16_t)(dp[i][j] + cnt[i + j - 1]));
            }
            if (i + j <= lim) {
                dp[i + j][j] = max(dp[i + j][j], (int16_t)(dp[i][j] + cnt[i + j]));
            }
            if (i + j + 1 <= lim) {
                dp[i + j + 1][j + 1] = max(dp[i + j + 1][j + 1], (int16_t)(dp[i][j] + cnt[i + j + 1]));
            }
        }
    }
    cout << ans;
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
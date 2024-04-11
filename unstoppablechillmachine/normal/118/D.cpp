#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,unroll-loops")
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
const int MOD = 1e8;
const int P = 239017;
const long long BINF = 1e18 + 10;

int dp[110][110][2][11];

_ void source() {
    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;
    dp[1][0][0][1] = 1;
    dp[0][1][1][1] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 1; k < k1; k++) {
                dp[i + 1][j][0][k + 1] += dp[i][j][0][k];
                dp[i + 1][j][0][k + 1] %= MOD;
                dp[i][j + 1][1][1] += dp[i][j][0][k];
                dp[i][j + 1][1][1] %= MOD;
            }
            dp[i][j + 1][1][1] += dp[i][j][0][k1];
            dp[i][j + 1][1][1] %= MOD;

            for (int k = 1; k < k2; k++) {
                dp[i][j + 1][1][k + 1] += dp[i][j][1][k];
                dp[i][j + 1][1][k + 1] %= MOD;
                dp[i + 1][j][0][1] += dp[i][j][1][k];
                dp[i + 1][j + 1][0][1] %= MOD;
            }
            dp[i + 1][j][0][1] += dp[i][j][1][k2];
            dp[i + 1][j][0][1] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= k1; i++) {
        ans += dp[n][m][0][i];
        ans %= MOD;
    }
    for (int i = 1; i <= k2; i++) {
        ans += dp[n][m][1][i];
        ans %= MOD;
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
#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll dp[maxn][2010][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    dp[1][1][0] = 2; dp[1][2][1] = 2;
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= 2 * n; j++) {
            dp[i][j][0] = (dp[i - 1][j - 1][0] + dp[i - 1][j][0] + 2 * dp[i - 1][j][1]) % mod;
            dp[i][j][1] = (2 * dp[i - 1][j - 1][0] + dp[i - 1][j][1]) % mod;
            if (j >= 2) {
                dp[i][j][1] += dp[i - 1][j - 2][1]; dp[i][j][1] %= mod;
            }
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            cout << i _ j _ dp[i][j][0] _ dp[i][j][1] << nl;
        }
        cout << nl;
    } */

    res = (dp[n][k][0] + dp[n][k][1]) % mod;
    cout << res << nl;

    return 0;
}
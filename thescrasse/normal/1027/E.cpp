// 1027E
// rettangoli con righe adiacenti uguali o opposte e senza sottorettangoli con area >= k

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, mod, dp[510][510];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 998244353;

    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (j == 0 || j == 1) {
                dp[i][j] = 2;
            } else if (j <= i) {
                dp[i][j] = (2 * dp[i][j - 1] + mod) % mod;
            } else {
                dp[i][j] = (2 * dp[i][j - 1] - dp[i][j - i - 1] + mod) % mod;
            }
        }
    }

    dp[0][0] = 0;
    for (i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    } */

    res = 0;
    for (i = 1; i <= n; i++) {
        // cout << i << ' ' << min((k - 1) / i, n) << endl;
        m = (mod + dp[i][n] - dp[i - 1][n]) * dp[min((k - 1) / i, n)][n];
        // cout << m << endl;
        res += m;
        res %= mod;
    }

    if (res % 2 == 1) {
        res += mod;
    }
    res /= 2;
    res %= mod;

    cout << res;

    return 0;
}
// 1077F2
// somma max di x a[j] tali che per ogni segmento lungo k  stato scelto un j

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, dp[2010][1010], mod, s[2010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 1000000007;
    cin >> n;
    dp[0][0] = 1;
    for (j = 1; j <= n; j++) {
        dp[0][j] = 0;
    }
    for (i = 1; i <= 2 * n; i++) {
        s[i] = 0;
        for (j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            }
            if (i > 2 * j) {
                dp[i][j] = 0;
            }
            s[i] = (s[i] + dp[i][j]) % mod;
        }
    }

    /* for (i = 0; i <= 2 * n; i++) {
        for (j = 0; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    } */

    res = 0;
    for (i = 1; i < 2 * n; i += 2) {
        res = (res + s[i]) % mod;
    }

    cout << res;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[100010], b, dp[100010][70];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (j = -30; j <= 30; j++) {
        dp[0][j + 30] = -INF;
    }
    dp[0][a[0] + 30] = 0;
    for (i = 1; i < n; i++) {
        for (j = -30; j <= 30; j++) {
            dp[i][j + 30] = -INF;
            if (a[i] < j) {
                dp[i][j + 30] = dp[i - 1][j + 30] + a[i];
            }
        }
        dp[i][a[i] + 30] = 0;
        for (j = -30; j <= a[i]; j++) {
            dp[i][a[i] + 30] = max(dp[i][a[i] + 30], dp[i - 1][j + 30] + j);
        }
    }

    res = 0;
    for (i = 0; i < n; i++) {
        for (j = -30; j <= 30; j++) {
            // cout << max((ll)-1000, dp[i][j + 30]) << ' ';
            res = max(res, dp[i][j + 30]);
        }
        // cout << endl;
    }

    cout << res;

    return 0;
}
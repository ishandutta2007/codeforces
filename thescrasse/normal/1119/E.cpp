// 1119E
// triangoli con lati potenze di 2

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, c[300010], dp[300010][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> c[i];
    }

    dp[0][0] = c[0] / 3;
    dp[0][1] = c[0] % 3;
    for (i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if (c[i] <= 2 * dp[i - 1][1]) {
            dp[i][0] += (c[i] / 2);
            dp[i][1] += ((c[i] % 2) - (c[i] / 2));
        } else {
            dp[i][0] += dp[i - 1][1];
            c[i] -= (2 * dp[i - 1][1]);
            dp[i][0] += (c[i] / 3);
            dp[i][1] = c[i] % 3;
        }
    }

    cout << dp[n - 1][0];

    return 0;
}
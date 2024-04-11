// 1114D
// colorazione di componenti connesse che partono sempre dallo stesso punto in un array

#include <bits/stdc++.h>
using namespace std;

#define INF 1e6

int i, i1, j, k, k1, t, n, m, res, check1, a, b, c[5010], dp[5010][5010][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        }
    }

    for (i = 0; i < n; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            dp[i][j][0] = min(dp[i][j][0], (dp[i + 1][j - 1][0] + (c[i] != c[i + 1])));
            dp[i][j][0] = min(dp[i][j][0], (dp[i + 1][j - 1][1] + (c[i] != c[i + j])));
            dp[i][j][1] = min(dp[i][j][1], (dp[i][j - 1][1] + (c[i + j - 1] != c[i + j])));
            dp[i][j][1] = min(dp[i][j][1], (dp[i][j - 1][0] + (c[i] != c[i + j])));
        }
    }

    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]);

    return 0;
}
// 1312E
// sostituzione di due a_i consecutivi con un a_i + 1

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[510], b, dp[510][510], dp2[510], d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i + 1];
    }

    for (d = 0; d < n; d++) {
        for (i = 1; i <= n - d; i++) {
            j = i + d;
            if (i == j) {
                dp[i][j] = a[i];
            } else {
                dp[i][j] = -1;
            }
            for (k = i + 1; k <= j; k++) {
                if (dp[i][k - 1] == dp[k][j] && dp[i][k - 1] != -1) {
                    dp[i][j] = dp[i][k - 1] + 1;
                    break;
                }
            }
            //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }

    dp2[1] = 1;
    for (i = 2; i <= n; i++) {
        dp2[i] = 100010;
        if (dp[1][i] != -1) {
            dp2[i] = 1;
        }
        for (j = 1; j < i; j++) {
            if (dp[j + 1][i] != -1) {
                dp2[i] = min(dp2[i], dp2[j] + 1);
            }
        }
        //cout << i << ' ' << dp2[i] << endl;
    }

    cout << dp2[n];

    return 0;
}
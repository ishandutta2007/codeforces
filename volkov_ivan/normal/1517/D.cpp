#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 507, K = 12, INF = 1e9 + 7;
int dp[N][N][K];
int w_gor[N][N];
int w_vert[N][N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++)
            cin >> w_gor[i][j];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> w_vert[i][j];
        }
    }
    if (k % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "-1 ";
            }
            cout << "\n";
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j][0] = 0;
            for (int t = 1; t <= k; t++) {
                dp[i][j][t] = INF;
            }
        }
    }

    for (int t = 0; t < k; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != n - 1)
                    dp[i + 1][j][t + 1] = min(dp[i + 1][j][t + 1], dp[i][j][t] + w_vert[i][j]);
                if (i != 0)
                    dp[i - 1][j][t + 1] = min(dp[i - 1][j][t + 1], dp[i][j][t] + w_vert[i - 1][j]);
                if (j != m - 1)
                    dp[i][j + 1][t + 1] = min(dp[i][j + 1][t + 1], dp[i][j][t] + w_gor[i][j]);
                if (j != 0)
                    dp[i][j - 1][t + 1] = min(dp[i][j - 1][t + 1], dp[i][j][t] + w_gor[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << 2 * dp[i][j][k / 2] << ' ';
        }
        cout << "\n";
    }
    return 0;
}
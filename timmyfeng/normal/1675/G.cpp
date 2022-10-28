#include <bits/stdc++.h>
using namespace std;

const int N = 251;

int dp[N][N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<int> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            for (int k = 0; k <= m; ++k) {
                dp[i][j][k] = n * m;
            }
        }
    }
    dp[0][m][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 0; --j) {
            for (int k = 0; k <= m; ++k) {
                if (j < m) dp[i][j][k] = min(dp[i][j][k], dp[i][j + 1][k]);
                if (k + j <= m) dp[i + 1][j][k + j] = min(dp[i + 1][j][k + j], dp[i][j][k] + abs(k - prefix[i]));
            }
        }
    }

    int answer = m * n;
    for (int i = 0; i <= m; ++i) {
        answer = min(answer, dp[n][i][m]);
    }

    cout << answer << "\n";
}
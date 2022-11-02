#include <cmath>
#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main() {
    int N, M;
    cin >> N >> M;

    int a[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }

    if (N == 1) {
        int ans = INF;
        for (int j = 0; j < M - 1; ++j) {
            ans = min(ans, abs(a[0][j + 1] - a[0][j]));
        }
        cout << ans << endl;
        return 0;
    }

    int cost[N][N], dcost[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cost[i][j] = INF;
            for (int k = 0; k < M; ++k) {
                cost[i][j] = min(cost[i][j], abs(a[i][k] - a[j][k]));
            }

            dcost[i][j] = INF;
            for (int k = 0; k < M - 1; ++k) {
                dcost[i][j] = min(dcost[i][j], abs(a[i][k + 1] - a[j][k]));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {

        int dp[1 << N][N];
        fill(dp[0], dp[1 << N], 0);
        dp[1 << i][i] = INF;

        for (int b = 0; b < (1 << N); ++b) {
            for (int k = 0; k < N; ++k) {
                if (((b >> k) & 1) == 0) continue;
                for (int l = 0; l < N; ++l) {
                    if ((b >> l) & 1) continue;
                    dp[b | (1 << l)][l] = max(dp[b | (1 << l)][l], min(dp[b][k], cost[k][l]));
                }
            }
        }

        for (int j = 0; j < N; ++j) {
            ans = max(ans, min(dp[(1 << N) - 1][j], dcost[i][j]));
        }
    }

    cout << ans << endl;
    return 0;
}
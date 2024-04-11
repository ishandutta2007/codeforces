#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int& i : A) cin >> i;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1e9));
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j < N; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            if (i == j - 1) {
                dp[i][j] = (A[i] != A[j]) + 1;
                continue;
            }
            dp[i][j] = (A[i] == A[j] ? dp[i + 1][j - 1] : 1e9);
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    cout << dp[0][N - 1] << "\n";
    return 0;
}
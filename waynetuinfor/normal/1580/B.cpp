#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, K, P;
  cin >> N >> M >> K >> P;
  vector<vector<int>> bin(N + 1, vector<int>(N + 1));
  for (int i = 0; i <= N; ++i) {
    bin[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1]) % P;
    }
  }
  vector<int> fc(N + 1, 1);
  for (int i = 1; i <= N; ++i) {
    fc[i] = 1LL * fc[i - 1] * i % P;
  }

  vector<vector<int>> dp(N + 1, vector<int>(K + 1));
  vector<vector<int>> nxt(N + 1, vector<int>(K + 1));

  for (int n = 1; n <= N; ++n) {
    dp[n][1] = fc[n];
  }
  dp[0][0] = fc[0];
  for (int m = 2; m <= M; ++m) {
    for (int n = 0; n <= N; ++n) {
      for (int k = 0; k <= min(n, K); ++k) {
        if (m > n) {
          if (k == 0) {
            nxt[n][k] = fc[n];
          } else {
            nxt[n][k] = 0;
          }
          continue;
        }
        __int128 d = 0;
        for (int left = 0; left < n; ++left) {
          int right = n - left - 1;
          __int128 s = 0;
          for (int x = 0; x <= min(left, k); ++x) {
            s += 1LL * dp[left][x] * dp[right][k - x];
          }
          d += (s % P) * bin[n - 1][left];
        }
        nxt[n][k] = d % P;
      }
    }
    dp.swap(nxt);
  }
  cout << dp[N][K] << "\n";
  return 0;
}
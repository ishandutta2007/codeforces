#include <bits/stdc++.h>
using namespace std;

const int N = 200'000 + 1;

int dp[N][2];
bool hard[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> hard[i];
    }

    if (n == 1) {
      cout << hard[0] << "\n";
      continue;
    }

    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[i][j] = n;
      }
    }

    dp[0][0] = hard[0];
    dp[1][0] = hard[0] + hard[1];

    for (int i = 0; i + 1 < n; ++i) {
      if (i + 2 < n) {
        dp[i + 2][1] = min(dp[i + 2][1], dp[i][0]);
        dp[i + 2][0] = min(dp[i + 2][0], dp[i][1] + hard[i + 1] + hard[i + 2]);
      }
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + hard[i + 1]);
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]) << "\n";
  }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int M = n * log2(1e18) + 1;
  const int inf = 1e9;
  vector<vector<int>> dp(k + 1, vector<int>(M, -inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    auto new_dp = dp;
    int x = 0, y = 0;
    while (a[i] > 0 && a[i] % 2 == 0) {
      x++;
      a[i] /= 2;
    }
    while (a[i] > 0 && a[i] % 5 == 0) {
      y++;
      a[i] /= 5;
    }
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < M; l++) {
        if (l + x >= M) {
          break;
        }
        new_dp[j + 1][l + x] = max(dp[j + 1][l + x], dp[j][l] + y);
      }
    }
    swap(new_dp, dp);
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    ans = max(ans, min(i, dp[k][i]));
  }
  cout << ans << '\n';
  return 0;
}
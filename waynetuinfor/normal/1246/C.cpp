#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];
  if (n == 1 && m == 1) {
    if (grid[0][0] == '.') cout << "1\n";
    else cout << "0\n";
    return 0;
  }
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2)));
  vector<vector<vector<int>>> sum(n, vector<vector<int>>(m, vector<int>(2)));
  vector<vector<vector<int>>> tag(n, vector<vector<int>>(m, vector<int>(2)));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      sum[i][j][0] = sum[i][j][1] = grid[i][j] == 'R';
      if (j + 1 < m) sum[i][j][0] += sum[i][j + 1][0];
      if (i + 1 < n) sum[i][j][1] += sum[i + 1][j][1];
    }
  }
  constexpr int kMod = 1'000'000'000 + 7;
  dp[0][0][0] = dp[0][0][1] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j > 0) (tag[i][j][0] += tag[i][j - 1][0]) %= kMod;
      if (i > 0) (tag[i][j][1] += tag[i - 1][j][1]) %= kMod;
      (dp[i][j][0] += tag[i][j][1]) %= kMod;
      (dp[i][j][1] += tag[i][j][0]) %= kMod;
      if (dp[i][j][0] > 0 && j + 1 < m) {
        int rock = sum[i][j + 1][0];
        (tag[i][j + 1][0] += dp[i][j][0]) %= kMod;
        if (rock > 0) (tag[i][m - rock][0] += kMod - dp[i][j][0]) %= kMod;
      }
      if (dp[i][j][1] > 0 && i + 1 < n) {
        int rock = sum[i + 1][j][1];
        (tag[i + 1][j][1] += dp[i][j][1]) %= kMod;
        if (rock > 0) (tag[n - rock][j][1] += kMod - dp[i][j][1]) %= kMod;
      }
    }
  }
  int ans = (dp[n - 1][m - 1][0] + dp[n - 1][m - 1][1]) % kMod;
  cout << ans << "\n";
  return 0;
}
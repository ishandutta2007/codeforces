#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<string> gr(n);
  for (int i = 0; i < n; ++i) cin >> gr[i];
  deque<pair<int, int>> q;
  constexpr int kMod = 1'000'000'000 + 123;
  vector<vector<int>> dp(n, vector<int>(m, 0));
  vector<vector<int>> dp2(n, vector<int>(m, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0 || gr[i][j] == '#') continue;
      if (i > 0) (dp[i][j] += dp[i - 1][j]) %= kMod;
      if (j > 0) (dp[i][j] += dp[i][j - 1]) %= kMod;
    }
  }
  if (dp[n - 1][m - 1] == 0) {
    cout << "0\n";
    return 0;
  }
  dp2[n - 1][m - 1] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (i == n - 1 && j == m - 1 || gr[i][j] == '#') continue;
      if (i + 1 < n) (dp2[i][j] += dp2[i + 1][j]) %= kMod;
      if (j + 1 < m) (dp2[i][j] += dp2[i][j + 1]) %= kMod;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) continue;
      if (i == n - 1 && j == m - 1) continue;
      int f = 1LL * dp[i][j] * dp2[i][j] % kMod;
      if (f == dp[n - 1][m - 1]) {
        cout << 1 << "\n";
        return 0;
      }
    }
  }
  cout << "2\n";
}
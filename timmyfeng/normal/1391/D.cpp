#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int dp[N][8];
string s[N];
int grid[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  if (min(n, m) >= 4) {
    cout << -1 << "\n";
    exit(0);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (m <= n) {
        grid[i] |= (s[i][j] - '0') << j;
      } else {
        grid[j] |= (s[i][j] - '0') << i;
      }
    }
  }

  if (n < m) {
    swap(n, m);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << m); ++j) {
      int delta = __builtin_popcount(grid[i] ^ j);
      if (i == 0) {
        dp[i][j] = delta;
      } else {
        dp[i][j] = n * m;
        for (int k = 0; k < (1 << m); ++k) {
          bool ok = true;
          for (int ii = 0; ii < m - 1; ++ii) {
            int cnt = __builtin_popcount((3 << ii) & j) + __builtin_popcount((3 << ii) & k);
            ok &= (cnt % 2 == 1);
          }
          if (ok) {
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + delta);
          }
        }
      }
    }
  }

  int ans = n * m;
  for (int i = 0; i < (1 << m); ++i) {
    ans = min(ans, dp[n - 1][i]);
  }
  cout << ans << "\n";
}
#include <bits/stdc++.h>

using namespace std;

int md;

int add(int x, int y) {
  x += y;
  return x >= md ? x - md : x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, b;
  cin >> n >> m >> b >> md;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<vector<int>>> dp(2, vector<vector<int>>(m + 5, vector<int>(b + 5)));
  dp[1][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int x = i & 1;
    int y = x ^ 1;
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= b; k++) {
        dp[x][j][k] = dp[y][j][k];
        if (j >= 1 && k >= a[i]) {
          dp[x][j][k] = add(dp[x][j][k], dp[x][j - 1][k - a[i]]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= b; i++) {
    ans = add(ans, dp[(n - 1) & 1][m][i]);
  }
  cout << ans << '\n';
  return 0;
}
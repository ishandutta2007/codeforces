#include <bits/stdc++.h>

using namespace std;

int st[1002][10][1002][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
          continue;
        }
        dp[i][j] = 1e9;
        if (i > 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
        if (j > 0) {
          dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
        if (i > 0 && j > 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
        dp[i][j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      st[i][0][j][0] = dp[i][j];
    }
  }
  const int LOG = 10;
  for (int x = 0; x < LOG; x++) {
    for (int y = 0; y < LOG; y++) {
      for (int i = 0; i + (1 << x) <= n; i++) {
        for (int j = 0; j + (1 << y) <= m; j++) {
          if (x > 0) {
            st[i][x][j][y] = max(st[i][x - 1][j][y], st[i + (1 << (x - 1))][x - 1][j][y]);
          }
          if (y > 0) {
            st[i][x][j][y] = max(st[i][x][j][y - 1], st[i][x][j + (1 << (y - 1))][y - 1]);
          }
        }
      }
    }
  }
  int mx_log = max(n, m);
  vector<int> logs(mx_log + 1);
  for (int i = 2; i <= mx_log; i++) {
    logs[i] = logs[i / 2] + 1;
  }
  auto Get = [&](int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return -1;
    int lgx = logs[x2 - x1 + 1];
    int lgy = logs[y2 - y1 + 1];
    return max({st[x1][lgx][y1][lgy],
               st[x2 - (1 << lgx) + 1][lgx][y1][lgy],
               st[x1][lgx][y2 - (1 << lgy) + 1][lgy],
               st[x2 - (1 << lgx) + 1][lgx][y2 - (1 << lgy) + 1][lgy]});
  };
  int qq;
  cin >> qq;
  while (qq--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    int bot = 1, top = min(x2 - x1, y2 - y1) + 2, ans = 0;
    while (bot <= top) {
      int mid = bot + top >> 1;
      if (Get(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid) {
        ans = mid;
        bot = mid + 1;
      } else {
        top = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  vector<pair<int, int>> a;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (y >= 0) {
      a.push_back({x, y});
    } else {
      x = max(x, abs(y));
      b.push_back({x, y});
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), [&](pair<int, int> x, pair<int, int> y) {
    return x.first + x.second > y.first + y.second;
  });
  int cnt = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    if (r < a[i].first) {
      continue;
    } else {
      r += a[i].second;
      cnt += 1;
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
  int mx = 0;
  dp[0][r] = cnt;
  for (int i = 0; i < (int) b.size(); i++) {
    for (int j = 0; j <= r; j++) {
      if (j >= b[i].first && j + b[i].second >= 0) {
        dp[i + 1][j + b[i].second] = max(dp[i + 1][j + b[i].second], dp[i][j] + 1);
      }
      mx = max(mx, dp[i][j]);
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    }
  }
  cout << *max_element(dp[(int) b.size()].begin(), dp[(int) b.size()].end()) << '\n';
  return 0;
}
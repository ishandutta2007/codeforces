#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<vector<int>> v(n);
    vector<vector<tuple<int, int, int, int>>> g(n);
    for (int i = 0; i < k; i++) {
      int a, b, c, d, h;
      cin >> a >> b >> c >> d >> h;
      --a; --b; --c; --d;
      v[a].push_back(b);
      v[c].push_back(d);
      g[a].push_back({b, c, d, h});
    }
    v[0].push_back(0);
    v[n - 1].push_back(m - 1);
    for (int i = 0; i < n; i++) {
      sort(v[i].begin(), v[i].end());
      v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    const long long inf = (long long) 1e18;
    vector<vector<long long>> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i].resize(v[i].size());
      fill(dp[i].begin(), dp[i].end(), inf);
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (j - 1 >= 0) {
          dp[i][j] = min(dp[i][j], dp[i][j - 1] + (long long) x[i] * abs(v[i][j] - v[i][j - 1]));
        }
      }
      for (int j = v[i].size() - 1; j >= 0; j--) {
        if (j + 1 < v[i].size()) {
          dp[i][j] = min(dp[i][j], dp[i][j + 1] + (long long) x[i] * abs(v[i][j + 1] - v[i][j]));
        }
      }
      for (auto nxt : g[i]) {
        int j = get<0>(nxt);
        int x = get<1>(nxt);
        int y = get<2>(nxt);
        int h = get<3>(nxt);
        j = lower_bound(v[i].begin(), v[i].end(), j) - v[i].begin();
        y = lower_bound(v[x].begin(), v[x].end(), y) - v[x].begin();
        dp[x][y] = min(dp[x][y], dp[i][j] - h);
      }
    }
    long long ans = dp[n - 1].back();
    if (ans >= (long long) 5e17) {
      cout << "NO ESCAPE" << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
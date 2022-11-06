#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector<vector<pair<int, int>>>> ev(k, vector<vector<pair<int, int>>>(2));
  for (int i = 0; i < m; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    for (int j = 0; j < k; ++j) {
      ev[j][x >> j & 1].emplace_back(l, r);
    }
  }

  constexpr int kMod = 998244353;

  vector<vector<int>> dp(n + 1, vector<int>(2));
  vector<vector<int>> g(n);
  vector<int> sum(n + 1), s(n), pref(n + 1);

  auto Solve = [&](const vector<pair<int, int>> &ev1, const vector<pair<int, int>> &ev2) {
    fill(s.begin(), s.end(), 0);
    for (auto [l, r] : ev1) {
      s[l]++;
      if (r + 1 < n) s[r + 1]--;
    }
    for (int i = 1; i < n; ++i) s[i] += s[i - 1];
    for (int i = 0; i < n; ++i) {
      if (s[i] > 0) s[i] = 1;
    }
    fill(pref.begin(), pref.end(), 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + s[i];
    fill(g.begin(), g.end(), vector<int>());
    for (auto [l, r] : ev2) {
      if (pref[r + 1] == pref[l] + (r - l + 1)) return 0;
      g[r].push_back(l);
    }
    fill(dp.begin(), dp.end(), vector<int>(2, 0));
    fill(sum.begin(), sum.end(), 0);
    dp[0][0] = 1;
    sum[0] = 1;
    int p = -1;
    for (int i = 0; i < n; ++i) {
      for (int u : g[i]) p = max(p, u);
      if (s[i] == 0) {
        dp[i + 1][0] = (dp[i][0] + dp[i][1]);
        dp[i + 1][0] >= kMod ? dp[i + 1][0] -= kMod : 0;
      }
      dp[i + 1][1] = sum[i];
      if (p >= 0) {
        (dp[i + 1][1] += kMod - sum[p]) >= kMod ? dp[i + 1][1] -= kMod : 0;
      }
      sum[i + 1] = (sum[i] + dp[i + 1][0]);
      sum[i + 1] >= kMod ? sum[i + 1] -= kMod : 0;
    }
    return (dp[n][0] + dp[n][1]) % kMod;
  };

  int res = 1;
  for (int i = 0; i < k; ++i) res = 1LL * res * Solve(ev[i][1], ev[i][0]) % kMod;
  cout << res << "\n";
  return 0;
}
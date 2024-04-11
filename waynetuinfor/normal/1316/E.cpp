#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<vector<int>> b(n, vector<int>(p));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p; ++j) cin >> b[i][j];
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] > a[j]; });

  constexpr int64_t kInf = 1'000'000'000'000'000;
  vector<int64_t> dp(1 << p, -kInf);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<int64_t> nxt(1 << p, -kInf);
    for (int s = 0; s < (1 << p); ++s) {
      if (i - __builtin_popcount(s) < k) nxt[s] = dp[s] + a[ord[i]];
      else nxt[s] = dp[s];
    }
    for (int s = 0; s < (1 << p); ++s) {
      for (int j = 0; j < p; ++j) {
        if (s >> j & 1) continue;
        nxt[s ^ (1 << j)] = max(nxt[s ^ (1 << j)], dp[s] + b[ord[i]][j]);
      }
    }
    dp = nxt;
  }
  cout << dp[(1 << p) - 1] << "\n";
  return 0;
}
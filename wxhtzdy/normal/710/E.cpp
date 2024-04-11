#include <bits/stdc++.h>

using ll = long long;

const int nmax = 20000005;

ll dp[nmax];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (int i = 1; i < nmax; i++) {
    dp[i] = 1e18;
  }
  int n, x, y;
  std::cin >> n >> x >> y;
  dp[1] = x;
  for (int i = 1; i <= n; i++) {
    dp[i + 1] = std::min(dp[i + 1], dp[i] + x);
    dp[i * 2] = std::min(dp[i * 2], dp[i] + y);
    dp[i * 2 - 1] = std::min(dp[i * 2 - 1], dp[i] + y + x);
  }
  ll ans = dp[n];
  for (int i = n + 1; i < nmax; i++) {
    ans = std::min(ans, dp[i] + (i - n) * 1LL * x);
  }
  std::cout << ans << "\n";
  return 0;
}
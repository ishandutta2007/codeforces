#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  std::vector<ll> dp(n);
  std::map<int, ll> cnt;
  for(int i = 0; i < n; i++) {
    if (i > 0) dp[i] = dp[i - 1];
    dp[i] += cnt[a[i]];
    cnt[a[i]] += i + 1;
  }
  std::cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}
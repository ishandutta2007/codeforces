#include <bits/stdc++.h>
using namespace std;

const long long A = 10'000'000'000'000LL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<long long, long long> dp;
  dp[A] = 0;

  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    auto it = dp.lower_bound(a);
    while (it != dp.end()) {
      auto [m, o] = *it;
      dp[m % a] = max(dp[m % a], o + (m - m % a) * i);
      dp[a - 1] = max(dp[a - 1], o + (m - m % a - a) * i);
      dp.erase(it);
      it = dp.lower_bound(a);
    }
  }

  long long ans = 0;
  for (auto [m, o] : dp) {
    ans = max(ans, m * n + o);
  }
  cout << ans << "\n";
}
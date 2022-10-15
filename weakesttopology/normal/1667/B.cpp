#include "bits/stdc++.h"

constexpr long long inf = std::numeric_limits<long long>::max() / 2;

int sgn(long long x) {
  return x <= 0 ? x < 0 ? -1 : 0 : +1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
    }
    std::vector<long long> p(N + 1);
    std::partial_sum(a.begin(), a.end(), p.begin() + 1);

    std::map<long long, long long> best, best_equal;
    auto insert_best = [&](long long key, long long value) {
      auto iter = best.find(key);
      if (iter == best.end()) {
        iter = best.insert({key, value}).first;
      } else {
        iter->second = std::max(iter->second, value);
      }
      if (iter != best.begin() && std::prev(iter)->second >= iter->second) {
        best.erase(iter);
      } else {
        while (std::next(iter) != best.end() && std::next(iter)->second <= iter->second) {
          best.erase(std::next(iter));
        }
      }
    };

    best[0] = 0;
    best_equal[0] = 0;
    std::vector<long long> dp(N + 1, -inf);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
      auto iter = best.lower_bound(p[i + 1]);
      if (iter != best.begin()) {
        dp[i + 1] = std::max(dp[i + 1], std::prev(iter)->second + i + 1);
      }
      if (best_equal.count(p[i + 1])) {
        dp[i + 1] = std::max(dp[i + 1], best_equal[p[i + 1]]);
      } else {
        best_equal[p[i + 1]] = -inf;
      }
      dp[i + 1] = std::max(dp[i + 1], dp[i] + sgn(a[i]));

      best_equal[p[i + 1]] = std::max(best_equal[p[i + 1]], dp[i + 1]);
      insert_best(p[i + 1], dp[i + 1] - (i + 1));
    }

    std::cout << dp[N] << '\n';
  }
  exit(0);
}
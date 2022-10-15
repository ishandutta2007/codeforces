#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<int64_t> x(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> x[i];
    }
    std::vector<int> a(K), b(K), c(K), d(K), h(K);
    std::vector<std::vector<int>> J(N);
    for (int j = 0; j < K; ++j) {
      std::cin >> a[j] >> b[j] >> c[j] >> d[j] >> h[j];
      --a[j], --b[j], --c[j], --d[j];
      J[a[j]].push_back(j);
    }
    a.push_back(N - 1);
    b.push_back(M - 1);
    c.push_back(N);
    d.push_back(M - 1);
    h.push_back(0);
    J[N - 1].push_back(K);
    J.emplace_back();
    x.push_back(0);
    ++N;
    std::vector<std::vector<std::pair<int, int64_t>>> dp(N);
    dp[0].push_back({0, 0});
    for (int i = 0; i < N; ++i) {
      std::sort(dp[i].begin(), dp[i].end());
      int Q = dp[i].size();
      std::vector<bool> dead(Q);
      for (int q = 0; q < Q; ++q) {
        int64_t cost = dp[i][q].second;
        while (q + 1 < Q) {
          int64_t ncost = cost + (dp[i][q + 1].first - dp[i][q].first) * x[i];
          if (ncost > dp[i][q + 1].second) break;
          dead[q + 1] = true;
          cost = ncost;
          ++q;
        }
      }
      for (int q = Q - 1; q >= 0; --q) {
        if (dead[q]) continue;
        int64_t cost = dp[i][q].second;
        while (q - 1 >= 0) {
          int64_t ncost = cost + (dp[i][q].first - dp[i][q - 1].first) * x[i];
          if (ncost > dp[i][q - 1].second) break;
          dead[q - 1] = true;
          cost = ncost;
          --q;
        }
      }
      std::vector<std::pair<int, int64_t>> ndp;
      for (int q = 0; q < Q; ++q) {
        if (!dead[q]) {
          ndp.push_back(dp[i][q]);
        }
      }
      std::swap(ndp, dp[i]);
      Q = dp[i].size();
      if (dp[i].empty()) continue;
      std::sort(J[i].begin(), J[i].end(), [&](int j1, int j2) { return b[j1] < b[j2]; });
      int q = 0;
      for (auto j : J[i]) {
        auto f = [&](int q) {
          return dp[i][q].second + x[i] * std::abs(dp[i][q].first - b[j]);
        };
        while (q + 1 < Q && dp[i][q + 1].first <= b[j]) ++q;
        int64_t cost = f(q);
        if (q + 1 < Q) {
          cost = std::min(cost, f(q + 1));
        }
        cost -= h[j];
        dp[c[j]].push_back({d[j], cost});
      }
    }
    if (dp[N - 1].empty()) {
      std::cout << "NO ESCAPE\n";
    } else {
      assert(dp[N - 1].size() == 1);
      std::cout << dp[N - 1][0].second << '\n';
    }
  }
  exit(0);
}
#include <bits/stdc++.h>
constexpr int K = 7;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  auto v = a;
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  int M = v.size();
  std::vector<std::array<int, K>> aux(M);
  std::vector dp(M, std::vector<int>(M));
  for (int i = 0; i < N; ++i) {
    int id = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    std::vector<int> ndp(M);
    for (auto pid : {id - 1, id + 1}) {
      if (0 <= pid && pid < M && std::abs(v[pid] - a[i]) == 1) {
        for (int j = 0; j < M; ++j) {
          ndp[j] = std::max(ndp[j], dp[pid][j] + 1);
        }
      }
    }
    for (int j = 0; j < M; ++j) {
      int k = a[i] % K;
      ndp[j] = std::max(ndp[j], aux[j][k] + 1);
    }
    for (int j = 0; j < M; ++j) {
      dp[j][id] = dp[id][j] = std::max(dp[id][j], ndp[j]);
      int k = a[i] % K;
      aux[j][k] = std::max(aux[j][k], ndp[j]);
      int l = v[j] % K;
      aux[id][l] = std::max(aux[id][l], ndp[j]);
    }
  }
  int ans = 0;
  for (auto& dp : dp) {
    ans = std::max(ans, *std::max_element(dp.begin(), dp.end()));
  }
  std::cout << ans << '\n';
  exit(0);
}
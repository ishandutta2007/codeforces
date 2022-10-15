#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < N; ++i) {
      int a;
      std::cin >> a;
      pos[a].push_back(i);
    }
    int ans = -1;
    for (auto [_, I] : pos) {
      int K = I.size();
      for (int k = 0; k + 1 < K; ++k) {
        int i = I[k], j = I[k + 1];
        ans = std::max(ans, i + N - j);
      }
    }
    std::cout << ans << '\n';
  }
  exit(0);
}
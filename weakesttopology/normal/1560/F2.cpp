#include <bits/stdc++.h>

bool beautiful(const std::string& S, int k) {
  bool vis[10]{};
  for (auto c : S) {
    vis[c - '0'] = true;
  }
  return std::accumulate(std::begin(vis), std::end(vis), 0) <= k;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::string N;
    int K;
    std::cin >> N >> K;
    std::string ans(N.size(), '9');
    int sz = N.size();
    for (int i = 0; i < sz; ++i) {
      auto S = N;
      for (char c = N[i] + 1; c <= '9'; ++c) {
        for (char d = '0'; d <= '9'; ++d) {
          S[i] = c;
          std::fill(S.begin() + i + 1, S.end(), d);
          if (beautiful(S, K) && S < ans) {
            ans = S;
          }
        }
      }
    }
    if (beautiful(N, K)) {
      ans = N;
    }
    std::cout << ans << '\n';
  }
  exit(0);
}
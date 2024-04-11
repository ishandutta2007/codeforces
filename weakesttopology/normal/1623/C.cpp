#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int64_t> h(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> h[i];
    }
    auto check = [&](int64_t x) {
      std::vector<int64_t> s(N);
      for (int i = N - 1; i >= 0; --i) {
        if (h[i] + s[i] < x) {
          return false;
        }
        if (i >= 2) {
          int64_t d = std::min(h[i] + s[i] - x, h[i]) / 3;
          s[i - 1] += d;
          s[i - 2] += 2 * d;
        }
      }
      return true;
    };
    int64_t L = 0, R = *std::max_element(h.begin(), h.end()) + 1;
    while (L + 1 < R) {
      int64_t M = L + (R - L) / 2;
      (check(M) ? L : R) = M;
    }
    std::cout << L << '\n';
  }
  exit(0);
}
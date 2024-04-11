#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int Q;
  std::cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int64_t N;
    std::cin >> N;
    int64_t L = 0, R = N;
    auto e = [&](int64_t M) {
      return M * (M - 1) / 2 + (N - M);
    };
    while (L + 1 < R) {
      int64_t M = (L + R) / 2;
      (e(M) >= e(M + 1) ? L : R) = M;
    }
    int64_t ans = N - 1;
    if (N - R >= (e(R) + 1) / 2) {
      L = R;
      R = N + 1;
      while (L + 1 < R) {
        int64_t M = (L + R) / 2;
        (N - M >= (e(M) + 1) / 2 ? L : R) = M;
      }
      ans = std::max(ans, e(L));
      if (R <= N) {
        int64_t b = N - R;
        ans = std::max(ans, 2 * b);
      }
    }
    std::cout << ans << '\n';
  }
  exit(0);
}
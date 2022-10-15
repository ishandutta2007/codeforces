#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::array<int64_t, 3> A[4] = {
    {0b00, 0b00, 0b00},
    {0b01, 0b10, 0b11},
    {0b10, 0b11, 0b01},
    {0b11, 0b01, 0b10},
  };
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int64_t N;
    std::cin >> N;
    --N;
    int o = N % 3;
    N /= 3;
    int64_t res = A[1][o];
    if (N) {
      --N;
      res <<= 2;
      for (int64_t pow = 4; pow <= N; pow *= 4) {
        N -= pow;
        res <<= 2;
      }
      for (int shift = 0; N; shift += 2, N /= 4) {
        res ^= A[N % 4][o] << shift;
      }
    }
    std::cout << res << '\n';
  }
  exit(0);
}
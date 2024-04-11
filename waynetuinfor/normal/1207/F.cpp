#include <array>
#include <iostream>

const int kBlock = 500;
const int kN = 500000 + 1;
std::array<std::array<long long, kBlock>, kBlock> sum{};
int a[kN];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    std::cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int j = 1; j < kBlock; ++j) sum[j][x % j] += y;
    } else {
      if (x >= kBlock) {
        long long ans = 0;
        for (int j = y; j < kN; j += x) ans += a[j];
        std::cout << ans << '\n';
      } else {
        std::cout << sum[x][y] << '\n';
      }
    }
  }
  return 0;
}
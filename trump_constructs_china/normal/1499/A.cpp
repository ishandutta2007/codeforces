#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int t, n, k1, k2, w, b;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k1 >> k2 >> w >> b;
    int cntw = std::min(k1, k2) + std::abs(k1 - k2) / 2,
        cntb = std::min(n - k1, n - k2) + std::abs(k1 - k2) / 2;
    if (w <= cntw && b <= cntb) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
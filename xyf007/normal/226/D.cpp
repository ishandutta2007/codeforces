#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, m, a[101][101], r[101], c[101];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  bool f = true;
  while (f) {
    f = false;
    for (int i = 1; i <= n; i++) {
      if (std::accumulate(a[i] + 1, a[i] + m + 1, 0) < 0) {
        f = true;
        r[i] ^= 1;
        for (int j = 1; j <= m; j++) {
          a[i][j] = -a[i][j];
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      int tmp = 0;
      for (int j = 1; j <= n; j++) {
        tmp += a[j][i];
      }
      if (tmp < 0) {
        f = true;
        c[i] ^= 1;
        for (int j = 1; j <= n; j++) {
          a[j][i] = -a[j][i];
        }
      }
    }
  }
  std::cout << std::count(r + 1, r + n + 1, 1) << ' ';
  for (int i = 1; i <= n; i++) {
    if (r[i]) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n' << std::count(c + 1, c + m + 1, 1) << ' ';
  for (int i = 1; i <= m; i++) {
    if (c[i]) {
      std::cout << i << ' ';
    }
  }
  return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int h1, a1, d1, h2, a2, d2, ph, pa, pd;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> h1 >> a1 >> d1 >> h2 >> a2 >> d2 >> ph >> pa >> pd;
  int ans = 0x3f3f3f3f;
  for (int i = 0; i <= 200; i++) {
    if (i + a1 <= d2) continue;
    for (int j = 0; j <= 200; j++) {
      if (a2 <= d1 + j) {
        checkmin(ans, pa * i + pd * j);
        break;
      }
      int da1 = i + a1 - d2, da2 = a2 - d1 - j, ti = (h2 + da1 - 1) / da1;
      checkmin(ans, ph * std::max(ti * da2 + 1 - h1, 0) + pa * i + pd * j);
    }
  }
  std::cout << ans;
  return 0;
}
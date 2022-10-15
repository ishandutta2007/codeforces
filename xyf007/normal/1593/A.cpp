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
int T, a, b, c;
void Solve() {
  std::cin >> a >> b >> c;
  std::cout << std::max(0, std::max(b + 1 - a, c + 1 - a)) << ' '
            << std::max(0, std::max(a + 1 - b, c + 1 - b)) << ' '
            << std::max(0, std::max(a + 1 - c, b + 1 - c)) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
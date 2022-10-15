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
constexpr long long kN = 1000000000LL;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
long long Ask(long long x, long long y) {
  std::cout << "? " << x << ' ' << y << std::endl;
  long long ans;
  std::cin >> ans;
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  long long d1 = Ask(1LL, 1LL), d2 = Ask(1LL, kN), d3 = Ask(kN, 1LL),
            d4 = Ask(kN, kN), y = (d1 - d2 + kN + 1) >> 1;
  long long x1 = Ask(1, y) + 1, y1 = d1 + 2 - x1, x2 = y1 - d3 + kN - 1,
            y2 = x1 + kN - 1 - d2;
  std::cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << std::endl;
  return 0;
}
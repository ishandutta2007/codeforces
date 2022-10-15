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
constexpr long long kInf = 1e9;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
std::string s;
bool Query(int x, int y) {
  std::cout << "? " << x << ' ' << y << std::endl;
  std::string ans;
  std::cin >> ans;
  return ans == "x";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  while (std::cin >> s && s != "end") {
    if (Query(0, 1)) {
      std::cout << "! 1" << std::endl;
      continue;
    }
    long long l = 0LL, r = 0LL;  // (l, r]
    for (long long i = 1LL; i <= 2 * kInf; i <<= 1)
      if (Query(i, 2 * std::min(i, kInf))) {
        l = i, r = 2 * std::min(i, kInf);
        break;
      }
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (Query(l, mid))
        r = mid;
      else
        l = mid;
    }
    std::cout << "! " << r << std::endl;
  }
  return 0;
}
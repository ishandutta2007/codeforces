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
long long c1, c2, x, y, lcm;
bool Check(long long mid) {
  long long cc1 = mid / y - mid / lcm, cc2 = mid / x - mid / lcm,
            rem = mid - cc1 - cc2 - mid / lcm, ne1 = std::max(c1 - cc1, 0LL),
            ne2 = std::max(c2 - cc2, 0LL);
  return ne1 + ne2 <= rem;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> c1 >> c2 >> x >> y, lcm = std::lcm(x, y);
  long long l = 0LL, r = 1e12, best = 1e12;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::cout << best;
  return 0;
}
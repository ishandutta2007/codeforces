#include <algorithm>
#include <cmath>
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
long long a, b;
long long Solve(long long s1, long long s2) {
  std::vector<int> d;
  for (int i = 1; 1LL * i * i <= s2; i++)
    if (!(s2 % i)) d.push_back(i);
  int p = (int)d.size() - 1;
  for (int i = std::sqrt(s1); i >= 1; --i)
    if (!(s1 % i)) {
      while (d[p] > i) --p;
      if (s2 / d[p] <= s1 / i) return 2LL * (i + s1 / i);
    }
  return 0x3f3f3f3f3f3f3f3fLL;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> a >> b;
  std::cout << std::min(Solve(a + b, a), Solve(a + b, b));
  return 0;
}
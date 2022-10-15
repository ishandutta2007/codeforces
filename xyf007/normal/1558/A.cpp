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
int T, a, b;
void Solve() {
  std::cin >> a >> b;
  int c0 = (a + b) >> 1, c1 = a + b - c0,
      max = std::min(a, c0) + std::min(b, c1),
      min = a + b - std::min(a, c1) - std::min(b, c0);
  std::set<int> s;
  for (int i = max; i >= min; i -= 2) s.emplace(i);
  std::swap(c0, c1);
  max = std::min(a, c0) + std::min(b, c1);
  min = a + b - std::min(a, c1) - std::min(b, c0);
  for (int i = max; i >= min; i -= 2) s.emplace(i);
  std::cout << s.size() << '\n';
  for (auto &&i : s) std::cout << i << ' ';
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
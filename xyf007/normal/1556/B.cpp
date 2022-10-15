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
int T, n, a[100001];
void Solve() {
  std::cin >> n;
  std::vector<int> p[2];
  for (int i = 1; i <= n; i++) std::cin >> a[i], p[a[i] & 1].emplace_back(i);
  if (std::abs(static_cast<int>(p[0].size()) - static_cast<int>(p[1].size())) >
      1) {
    std::cout << "-1\n";
    return;
  }
  if (n & 1) {
    long long ans = 0LL;
    if (p[0].size() < p[1].size()) std::swap(p[0], p[1]);
    std::size_t p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++)
      if (i & 1)
        ans += std::abs(p[0][p1++] - i);
      else
        ans += std::abs(p[1][p2++] - i);
    std::cout << ans / 2 << '\n';
    return;
  } else {
    long long s1 = 0LL, s2 = 0LL;
    std::size_t p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++)
      if (i & 1)
        s1 += std::abs(p[0][p1++] - i);
      else
        s1 += std::abs(p[1][p2++] - i);
    std::swap(p[0], p[1]);
    p1 = p2 = 0;
    for (int i = 1; i <= n; i++)
      if (i & 1)
        s2 += std::abs(p[0][p1++] - i);
      else
        s2 += std::abs(p[1][p2++] - i);
    std::cout << std::min(s1, s2) / 2 << '\n';
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
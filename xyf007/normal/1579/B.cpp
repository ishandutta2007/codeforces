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
int T, n, a[51];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::vector<std::tuple<int, int, int>> ans;
  for (int i = 1; i < n; i++) {
    int p = i;
    for (int j = i + 1; j <= n; j++)
      if (a[j] < a[p]) p = j;
    if (p == i) continue;
    ans.emplace_back(i, p, p - i);
    std::rotate(a + i, a + p, a + p + 1);
  }
  std::cout << ans.size() << '\n';
  for (auto &&[l, r, d] : ans) std::cout << l << ' ' << r << ' ' << d << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
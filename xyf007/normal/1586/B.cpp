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
int T, n, m;
void Solve() {
  std::cin >> n >> m;
  std::set<int> vis;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    vis.emplace(b);
  }
  for (int i = 1; i <= n; i++)
    if (!vis.count(i)) {
      for (int j = 1; j < i; j++) std::cout << i << ' ' << j << '\n';
      for (int j = i + 1; j <= n; j++) std::cout << i << ' ' << j << '\n';
      return;
    }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
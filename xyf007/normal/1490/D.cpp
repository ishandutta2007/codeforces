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
int T, n, a[101], dep[101];
void Dfs(int l, int r, int d) {
  if (l > r) return;
  int p = std::max_element(a + l, a + r + 1) - a;
  dep[p] = d;
  Dfs(l, p - 1, d + 1), Dfs(p + 1, r, d + 1);
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  Dfs(1, n, 0);
  for (int i = 1; i <= n; i++) std::cout << dep[i] << " \n"[i == n];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
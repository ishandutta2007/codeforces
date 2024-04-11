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
int T, n, m, a[301];
bool vis[301];
void Solve() {
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> v;
  for (int i = 1; i <= m; i++) std::cin >> a[i], v.emplace_back(a[i], -i);
  std::sort(v.begin(), v.end());
  int ans = 0;
  for (auto [x, y] : v) {
    int pos = -y;
    for (int i = 1; i <= pos; i++) ans += vis[i];
    vis[pos] = true;
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= m; i++) vis[i] = false;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
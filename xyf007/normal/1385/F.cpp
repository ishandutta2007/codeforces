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
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  for (auto &&x : v) out << x << ' ';
  return out;
}
int T, n, k;
void Solve() {
  std::cin >> n >> k;
  std::set<int> g[n + 1];
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace(v), g[v].emplace(u);
  }
  if (k == 1) {
    std::cout << n - 1 << '\n';
    return;
  }
  std::vector<int> deg(n + 1);
  for (int u = 1; u <= n; u++)
    for (auto &&v : g[u]) deg[u] += g[v].size() == 1;
  std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> s;
  for (int i = 1; i <= n; i++)
    if (deg[i] >= k) s.emplace(deg[i], i);
  int ans = 0;
  while (!s.empty()) {
    int u = s.begin()->second;
    s.erase(s.begin());
    int tmp = deg[u] / k * k;
    ans += deg[u] / k;
    deg[u] %= k;
    for (auto it = g[u].begin(); tmp;) {
      int v = *it;
      if (g[v].size() == 1)
        tmp--, it = g[u].erase(it), g[v].erase(u);
      else
        ++it;
    }
    if (!deg[u] && g[u].size() == 1) {
      int fa = *g[u].begin();
      s.erase({deg[fa]++, fa});
      s.emplace(deg[fa], fa);
    }
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
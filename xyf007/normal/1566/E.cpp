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
int T, n, cnt[200001];
std::vector<int> g[200001];
void Dfs(int u, int fa) {
  cnt[u] = 0;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u);
    if (!cnt[v]) cnt[u]++;
  }
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs(1, 0);
  int ans = 0;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) continue;
    ans += cnt[i] - ok;
    ok = true;
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; i++) g[i].clear();
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
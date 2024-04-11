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
int n, a[200001], b[200001], c[200001], d[200001][2];
long long ans = 0LL;
std::vector<int> g[200001];
void Dfs(int u, int fa) {
  if (b[u] != c[u]) d[u][b[u]]++;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    checkmin(a[v], a[u]);
    Dfs(v, u);
    d[u][0] += d[v][0], d[u][1] += d[v][1];
  }
  int min = std::min(d[u][0], d[u][1]);
  ans += 2LL * min * a[u];
  d[u][0] -= min, d[u][1] -= min;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i] >> c[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  if (std::accumulate(b + 1, b + n + 1, 0) !=
      std::accumulate(c + 1, c + n + 1, 0)) {
    std::cout << -1;
    return 0;
  }
  Dfs(1, 0);
  std::cout << ans;
  return 0;
}
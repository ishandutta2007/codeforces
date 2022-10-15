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
int n, dep[200001], fa[200001];
std::vector<int> g[200001];
bool vis[200001];
void Dfs(int u, int f) {
  dep[u] = dep[fa[u] = f] + 1;
  for (auto &&v : g[u]) {
    if (v == f) continue;
    Dfs(v, u);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs(1, 0);
  std::priority_queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++)
    if (dep[i] > 3) q.emplace(dep[i], i);
  int ans = 0;
  while (!q.empty()) {
    int u = q.top().second, f = fa[u];
    q.pop();
    if (vis[u]) continue;
    ans++;
    for (auto &&v : g[f]) vis[v] = true;
    vis[f] = true;
  }
  std::cout << ans;
  return 0;
}
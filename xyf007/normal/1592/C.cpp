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
int T, n, k, s, a[200001], cnt;
std::vector<int> g[200001];
bool vis[200001];
void Dfs(int u, int fa) {
  bool hv = false;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u), a[u] ^= a[v], hv |= vis[v];
  }
  if (!hv && a[u] == s) cnt++;
  vis[u] = hv || a[u] == s;
}
bool Dfs(int u, int fa, int f) {
  if (a[u] == s && f) return true;
  f |= !a[u];
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    if (Dfs(v, u, f)) return true;
  }
  return false;
}
void Solve() {
  std::cin >> n >> k;
  s = 0;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; i++) s ^= a[i];
  if (!s) {
    std::cout << "YES\n";
    return;
  }
  if (k == 2) {
    std::cout << "NO\n";
    return;
  }
  cnt = 0;
  Dfs(1, 0);
  if (cnt > 1) {
    std::cout << "YES\n";
    return;
  }
  if (Dfs(1, 0, false)) {
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
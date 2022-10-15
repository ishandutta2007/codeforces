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
int n, m, q;
class DisjointSet {
 public:
  DisjointSet() {}
  void Init(int n) { std::iota(fa_ + 1, fa_ + n + 1, 1); }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    fa_[fx] = fy;
    return true;
  }
  ~DisjointSet() {}

 private:
  int fa_[300001];
} dsu;
std::vector<std::pair<int, int>> g[300001];
int dep[300001], fa[300001], fe[300001], cnt[300001], deg[300001];
void Dfs(int u, int f) {
  dep[u] = dep[fa[u] = f] + 1;
  for (auto &&[v, eid] : g[u]) {
    if (v == f) continue;
    fe[v] = eid, Dfs(v, u);
  }
}
std::vector<int> r[300001][2];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m, dsu.Init(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    if (dsu.Merge(u, v)) g[u].emplace_back(v, i), g[v].emplace_back(u, i);
  }
  Dfs(1, 0);
  std::cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v;
    std::cin >> u >> v;
    while (dep[u] > dep[v]) r[i][0].emplace_back(u), cnt[fe[u]] ^= 1, u = fa[u];
    while (dep[v] > dep[u]) r[i][1].emplace_back(v), cnt[fe[v]] ^= 1, v = fa[v];
    while (u != v) {
      r[i][0].emplace_back(u), cnt[fe[u]] ^= 1, u = fa[u];
      r[i][1].emplace_back(v), cnt[fe[v]] ^= 1, v = fa[v];
    }
    r[i][0].emplace_back(u);
    std::reverse(r[i][1].begin(), r[i][1].end());
    r[i][0].insert(r[i][0].end(), r[i][1].begin(), r[i][1].end());
  }
  for (int i = 1; i <= n; i++)
    for (auto &&[v, eid] : g[i]) deg[i] ^= cnt[eid];
  int ans = std::accumulate(deg + 1, deg + n + 1, 0) >> 1;
  if (ans == 0) {
    std::cout << "YES\n";
    for (int i = 1; i <= q; i++) {
      std::cout << r[i][0].size() << '\n';
      for (auto &&x : r[i][0]) std::cout << x << ' ';
      std::cout << '\n';
    }
  } else {
    std::cout << "NO\n" << ans << '\n';
  }
  return 0;
}
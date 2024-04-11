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
int n, m, dis[201], cnt[201], ans = 0xcfcfcfcf, p;
bool vis[201];
std::vector<std::pair<int, int>> g[201];
std::vector<int> g2[201];
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
  int fa_[401];
} T;
void Solve(int x) {
  std::memset(dis, 0x3f, sizeof(dis)), dis[x] = 0;
  std::memset(vis, false, sizeof(vis));
  std::memset(cnt, 0, sizeof(cnt));
  std::queue<int> q;
  q.emplace(x), vis[x] = true, cnt[x]++;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = false;
    for (auto &&[v, w] : g[u])
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        if (!vis[v]) {
          q.emplace(v), vis[v] = true;
          if (++cnt[v] > n + 1) return;
        }
      }
  }
  int max = *std::max_element(dis + 1, dis + n + 1);
  if (max > ans) ans = max, p = x;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  T.Init(2 * n);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    if (c)
      g[u].emplace_back(v, 1), g[v].emplace_back(u, -1);
    else
      g[u].emplace_back(v, 1), g[v].emplace_back(u, 1);
    T.Merge(u, v + n), T.Merge(v, u + n);
  }
  for (int i = 1; i <= n; i++)
    if (T.Find(i) == T.Find(i + n)) {
      std::cout << "NO";
      return 0;
    }
  for (int i = 1; i <= n; i++) Solve(i);
  if (ans < 0) {
    std::cout << "NO";
    return 0;
  }
  Solve(p);
  std::cout << "YES\n" << ans << '\n';
  for (int i = 1; i <= n; i++) std::cout << dis[i] << ' ';
  return 0;
}
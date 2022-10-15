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
int n, m, d;
std::vector<int> a, g[200001];
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
  int fa_[200001];
} T;
bool vis[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> d;
  T.Init(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    if (u > v) std::swap(u, v);
    if (u == 1)
      a.emplace_back(v);
    else
      T.Merge(u, v), g[u].emplace_back(v), g[v].emplace_back(u);
  }
  int cnt = 0;
  for (int i = 2; i <= n; i++) cnt += T.Find(i) == i;
  if (static_cast<int>(a.size()) < d || cnt > d) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";
  for (auto &&u : a) {
    if (vis[T.Find(u)]) continue;
    g[1].emplace_back(u);
    vis[T.Find(u)] = true;
    u = -1;
    d--;
  }
  for (auto &&u : a) {
    if (!d) break;
    if (u == -1) continue;
    g[1].emplace_back(u), d--;
  }
  std::queue<int> q;
  std::memset(vis, false, sizeof(vis));
  q.emplace(1), vis[1] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &&v : g[u]) {
      if (vis[v]) continue;
      std::cout << u << ' ' << v << '\n';
      q.emplace(v), vis[v] = true;
    }
  }
  return 0;
}
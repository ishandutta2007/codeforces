#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
struct Edge {
  int to, nxt, cost;
} e[200001];
int n, q, E, head[100001], x, y, id[100001], fa[100001], sz[100001],
    dep[100001];
long long dis[100001], a[100001], ans;
std::vector<int> g[100001];
void checkmax(long long &x, long long y) {
  if (x < y) {
    x = y;
  }
}
void Add(int f, int t, int c) {
  e[E].to = t;
  e[E].cost = c;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int fa) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) {
      continue;
    }
    dis[v] = dis[u] + e[i].cost;
    Dfs(v, u);
  }
}
void Dfs2(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) {
      continue;
    }
    g[u].emplace_back(v);
    Dfs2(v, u);
  }
}
int Find(int x) {
  if (x == fa[x]) {
    return x;
  }
  return fa[x] = Find(fa[x]);
}
void Merge(int x, int y) {
  int fx = Find(x), fy = Find(y);
  if (fx == fy) {
    return;
  }
  fa[fx] = fy;
  checkmax(ans, sz[fy] += sz[fx]);
}
void Erase(int x) { sz[Find(x)]--; }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    Add(u, v, c);
    Add(v, u, c);
  }
  Dfs(1, 0);
  x = std::max_element(dis + 1, dis + n + 1) - dis;
  dis[x] = 0;
  Dfs(x, 0);
  y = std::max_element(dis + 1, dis + n + 1) - dis;
  std::memcpy(a + 1, dis + 1, 8 * n);
  dis[y] = 0;
  Dfs(y, 0);
  for (int i = 1; i <= n; i++) {
    checkmax(a[i], dis[i]);
  }
  int rt = std::min_element(a + 1, a + n + 1) - a;
  Dfs2(rt, 0);
  std::iota(id + 1, id + n + 1, 1);
  std::sort(id + 1, id + n + 1, [](const int &x, const int &y) -> bool {
    return a[x] == a[y] ? dep[x] > dep[y] : a[x] > a[y];
  });
  std::cin >> q;
  while (q--) {
    long long d;
    std::cin >> d;
    std::iota(fa + 1, fa + n + 1, 1);
    std::fill(sz + 1, sz + n + 1, 1);
    ans = 1LL;
    int r = 1;
    for (int l = 1; l <= n; l++) {
      while (r < n && a[id[l]] - a[id[r + 1]] <= d) {
        int u = id[++r];
        for (auto &&v : g[u]) {
          Merge(u, v);
        }
      }
      Erase(id[l]);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
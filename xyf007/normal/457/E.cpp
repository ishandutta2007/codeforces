#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
struct Edge {
  int u, v, w;
} e[200001];
int n, m, dis[200001], col[200001], c, max[200001], min[200001];
std::vector<std::pair<int, int>> g[200001];
bool vis[200001];
bool Bfs(int s) {
  std::queue<int> q;
  q.emplace(s), vis[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    col[u] = c;
    for (const auto &[v, w] : g[u])
      if (!vis[v])
        dis[v] = dis[u] + w, q.emplace(v), vis[v] = true;
      else if (dis[u] + w != dis[v])
        return false;
  }
  return true;
}
bool Check(int x) {
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= x; i++) {
    auto [u, v, w] = e[i];
    g[u].emplace_back(v, w), g[v].emplace_back(u, -w);
  }
  std::fill(vis + 1, vis + n + 1, false);
  std::fill(dis + 1, dis + n + 1, 0);
  c = 0, std::fill(col + 1, col + n + 1, 0);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      c++;
      if (!Bfs(i)) return false;
    }
  for (int i = 2; i <= n; i++)
    if (col[i] == 1 && dis[i] <= 0) return false;
  for (int i = 2; i < n; i++)
    if (col[i] == col[n] && dis[i] >= dis[n]) return false;
  if (col[1] != col[n]) return true;
  std::fill(max + 2, max + c + 1, 0x80808080);
  std::fill(min + 2, min + c + 1, 0x7f7f7f7f);
  for (int i = 1; i <= n; i++)
    checkmax(max[col[i]], dis[i]), checkmin(min[col[i]], dis[i]);
  for (int i = 2; i <= c; i++)
    if (max[i] - min[i] >= dis[n]) return false;
  return true;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w, s;
    std::cin >> u >> v >> w >> s;
    e[i] = {u, v, w * s};
  }
  if (Check(m)) {
    if (col[1] == col[n]) {
      std::cout << dis[n];
    } else {
      std::cout << "UNKNOWN";
    }
    return 0;
  }
  int l = 1, r = m, best = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (!Check(mid))
      best = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  std::cout << "BAD " << best;
  return 0;
}
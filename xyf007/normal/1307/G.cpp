#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int u, v, w;
} e[2501];
int n, m, q, f[2501], tot;
namespace flow {
struct Edge {
  int to, nxt, flow, cost;
} e[10001];
int E, head[51], dis[51], pre[51], le[51], flow[51];
bool vis[51];
void Add(int f, int t, int w, int c) {
  e[E] = {t, head[f], w, c}, head[f] = E++;
}
void Build() {
  std::fill(head + 1, head + n + 1, -1);
  for (int i = 1; i <= m; i++) {
    int u = ::e[i].u, v = ::e[i].v, w = ::e[i].w;
    Add(u, v, 1, w), Add(v, u, 0, -w);
  }
}
bool Spfa() {
  std::fill(dis + 2, dis + n + 1, 0x3f3f3f3f);
  flow[1] = 1, pre[n] = -1;
  std::queue<int> q;
  q.emplace(1), vis[1] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = false;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      if (!e[i].flow) continue;
      int v = e[i].to;
      if (dis[u] + e[i].cost < dis[v]) {
        dis[v] = dis[u] + e[i].cost, pre[v] = u;
        le[v] = i, flow[v] = std::min(flow[u], e[i].flow);
        if (!vis[v]) q.emplace(v), vis[v] = true;
      }
    }
  }
  return pre[n] != -1;
}
void MinCostMaxFlow() {
  while (Spfa()) {
    f[tot + 1] = f[tot] + dis[n] * flow[n], tot++;
    for (int i = n; i != 1; i = pre[i])
      e[le[i]].flow -= flow[n], e[le[i] ^ 1].flow += flow[n];
  }
}
}  // namespace flow
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) std::cin >> e[i].u >> e[i].v >> e[i].w;
  flow::Build();
  flow::MinCostMaxFlow();
  std::cout.precision(8), std::cout << std::fixed;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;
    double ans = 1e15;
    for (int i = 1; i <= tot; i++)
      checkmin(ans, static_cast<double>(x + f[i]) / i);
    std::cout << ans << '\n';
  }
  return 0;
}
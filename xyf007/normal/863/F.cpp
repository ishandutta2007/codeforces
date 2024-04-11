#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <algorithm>
#include <iostream>
#include <queue>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, L[51], R[51];
namespace flow {
struct Edge {
  int to, nxt, flow, cost;
} e[20001];
int s, t, E, head[105], dis[105], pre[105], le[105], flow[105];
bool vis[105];
void Add(int f, int t, int w, int c) {
  e[E] = {t, head[f], w, c}, head[f] = E++;
}
void Build() {
  t = 2 * n + 1;
  std::fill(head, head + t + 1, -1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      Add(s, i, 1, 2 * j - 1), Add(i, s, 0, 1 - 2 * j);
    for (int j = 1; j <= n; j++)
      if (L[j] <= i && i <= R[j]) Add(i, j + n, 1, 0), Add(j + n, i, 0, 0);
    Add(n + i, t, 1, 0), Add(t, n + i, 0, 0);
  }
}
bool Spfa() {
  std::fill(dis + 1, dis + t + 1, 0x3f3f3f3f);
  flow[s] = 0x3f3f3f3f;
  std::queue<int> q;
  q.emplace(s), vis[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = false;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      if (!e[i].flow) continue;
      int v = e[i].to;
      if (dis[u] + e[i].cost < dis[v]) {
        dis[v] = dis[u] + e[i].cost;
        pre[v] = u, le[v] = i, flow[v] = std::min(flow[u], e[i].flow);
        if (!vis[v]) q.emplace(v), vis[v] = true;
      }
    }
  }
  return dis[t] != 0x3f3f3f3f;
}
int MinCostMaxFlow() {
  int ans = 0;
  while (Spfa()) {
    for (int i = t; i; i = pre[i])
      e[le[i]].flow -= flow[t], e[le[i] ^ 1].flow += flow[t];
    ans += dis[t] * flow[t];
  }
  return ans;
}
}  // namespace flow
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  std::fill(L + 1, L + n + 1, 1), std::fill(R + 1, R + n + 1, n);
  for (int i = 1; i <= m; i++) {
    int op, l, r, v;
    std::cin >> op >> l >> r >> v;
    if (op == 1)
      for (int j = l; j <= r; j++) checkmax(L[j], v);
    else
      for (int j = l; j <= r; j++) checkmin(R[j], v);
  }
  for (int i = 1; i <= n; i++)
    if (L[i] > R[i]) {
      std::cout << -1;
      return 0;
    }
  flow::Build();
  std::cout << flow::MinCostMaxFlow();
  return 0;
}
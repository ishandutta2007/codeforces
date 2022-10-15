#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
struct Edge {
  int to, nxt, cost;
} e[200001];
int n, m, E, head[100001], dis[100001];
std::set<int> s[100001];
bool vis[100001];
void Add(int f, int t, int c) {
  e[E].to = t;
  e[E].cost = c;
  e[E].nxt = head[f];
  head[f] = E++;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    Add(u, v, c);
    Add(v, u, c);
  }
  for (int i = 1; i <= n; i++) {
    int k, x;
    std::cin >> k;
    for (int j = 1; j <= k; j++) {
      std::cin >> x;
      s[i].emplace(x);
    }
  }
  std::memset(dis, 0x3f, sizeof(dis));
  dis[1] = 0;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      q;
  q.emplace(0, 1);
  while (!q.empty()) {
    int u = q.top().second, d = q.top().first;
    q.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    while (s[u].count(d)) {
      d++;
    }
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (d + e[i].cost < dis[v]) {
        dis[v] = d + e[i].cost;
        q.emplace(dis[v], v);
      }
    }
  }
  if (dis[n] == 0x3f3f3f3f) {
    std::cout << -1;
  } else {
    std::cout << dis[n];
  }
  return 0;
}
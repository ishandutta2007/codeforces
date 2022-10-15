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
struct Edge {
  int to, nxt, cost;
} e[200001];
int n, m, E, head[100001], dis[100001], dp[100001], pre[100001];
bool vis[100001];
void Add(int f, int t, int c) {
  e[E] = {t, head[f], c};
  head[f] = E++;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    Add(u, v, c), Add(v, u, c);
  }
  std::memset(dis, 0x3f, sizeof(dis));
  dis[1] = 0;
  std::queue<int> q;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to, c = e[i].cost;
      if (dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1, dp[v] = dp[u] + (c ^ 1), pre[v] = i;
        q.emplace(v);
      } else if (dis[u] + 1 == dis[v]) {
        if (dp[u] + (c ^ 1) < dp[v]) {
          dp[v] = dp[u] + (c ^ 1), pre[v] = i;
        }
      }
    }
  }
  for (int p = n; p != 1; p = e[pre[p] ^ 1].to) vis[pre[p] >> 1] = true;
  std::vector<std::tuple<int, int, int>> ans;
  for (int i = 0; i < m; i++) {
    int u = e[2 * i + 1].to, v = e[2 * i].to, c = e[2 * i].cost;
    if ((vis[i] && !c) || (!vis[i] && c)) ans.emplace_back(u, v, c ^ 1);
  }
  std::cout << ans.size() << '\n';
  for (auto &&[u, v, c] : ans) std::cout << u << ' ' << v << ' ' << c << '\n';
  return 0;
}
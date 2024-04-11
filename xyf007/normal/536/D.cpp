#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int to, nxt;
  long long cost;
} e[200001];
int n, m, S, T, E, head[2005], seq1[2005], seq2[2005], c[2005][2005], c1, c2,
    ns[2005][2005], nt[2005][2005];
long long a[2005], dis[2][2005], s[2005][2005], f[2005][2005], g[2005][2005];
void Add(int f, int t, long long c) { e[E] = {t, head[f], c}, head[f] = E++; }
void Dijkstra(long long dis[], int s, int &c) {
  std::memset(dis + 1, 0x3f, 8 * n);
  dis[s] = 0LL;
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>>

      q;
  q.emplace(0LL, s);
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (dis[u] < d) continue;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (dis[u] + e[i].cost < dis[v])
        dis[v] = dis[u] + e[i].cost, q.emplace(dis[v], v);
    }
  }
  long long b[2005];
  std::memcpy(b + 1, dis + 1, 8 * n);
  std::sort(b + 1, b + n + 1);
  c = std::unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++)
    dis[i] = std::lower_bound(b + 1, b + c + 1, dis[i]) - b;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> S >> T;
  std::memset(head + 1, -1, 4 * n);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long c;
    std::cin >> u >> v >> c;
    Add(u, v, c), Add(v, u, c);
  }
  Dijkstra(dis[0], S, c1), Dijkstra(dis[1], T, c2);
  for (int i = 1; i <= n; i++)
    c[dis[0][i]][dis[1][i]]++, s[dis[0][i]][dis[1][i]] += a[i];
  for (int i = c1; i >= 1; i--)
    for (int j = c2; j >= 1; j--) {
      s[i][j] += s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1];
      ns[i][j] =
          std::min(i == c1 ? c1 : ns[i + 1][j], j == c2 ? c1 : ns[i][j + 1]);
      nt[i][j] =
          std::min(i == c1 ? c2 : nt[i + 1][j], j == c2 ? c2 : nt[i][j + 1]);
      if (c[i][j]) ns[i][j] = i, nt[i][j] = j;
      f[i][j] = s[i][j] - g[ns[i][j] + 1][j];
      g[i][j] = s[i][j] - f[i][nt[i][j] + 1];
      if (i == 1 && j == 1) continue;
      f[i][j] = std::min(f[i][j], f[i][j + 1]);
      g[i][j] = std::min(g[i][j], g[i + 1][j]);
    }
  long long d = s[1][1] - 2 * f[1][1];
  std::cout << (d == 0 ? "Flowers" : d < 0 ? "Break a heart" : "Cry");
  return 0;
}
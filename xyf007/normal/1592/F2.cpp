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
int n, m, a[505][505], sum[505][505];
char s[505][505];
namespace maxflow {
struct Edge {
  int to, nxt, cost;
} e[200001];
int s, t, E, head[10001], cur[10001], dep[10001];
void Add(int f, int t, int c) {
  e[E] = {t, head[f], c};
  head[f] = E++;
}
void Build() {
  t = n + m + 1;
  std::memset(head, -1, 4 * (t + 1));
  for (int i = 1; i <= n; i++) Add(s, i, 1), Add(i, s, 0);
  for (int i = 1; i <= m; i++) Add(n + i, t, 1), Add(t, n + i, 0);
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      if (sum[i][j] && sum[n][j] && sum[i][m])
        Add(i, n + j, 1), Add(n + j, i, 0);
}
bool Bfs() {
  std::memset(dep + 1, -1, 4 * t);
  std::memcpy(cur, head, 4 * (t + 1));
  std::queue<int> q;
  q.emplace(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      if (!e[i].cost) continue;
      int v = e[i].to;
      if (dep[v] == -1) dep[v] = dep[u] + 1, q.emplace(v);
    }
  }
  return dep[t] != -1;
}
int Dfs(int u, int sum) {
  if (u == t || !sum) return sum;
  int ans = 0;
  for (int i = cur[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (dep[v] == dep[u] + 1 && e[i].cost) {
      int min = Dfs(v, std::min(sum, e[i].cost));
      if (min) {
        e[i].cost -= min, e[i ^ 1].cost += min;
        ans += min, sum -= min;
        if (!sum) break;
      }
    }
    cur[u] = e[i].nxt;
  }
  if (!ans) dep[u] = -1;
  return ans;
}
int MaxFlow() {
  int ans = 0;
  while (Bfs()) ans += Dfs(s, 0x3f3f3f3f);
  return ans;
}
}  // namespace maxflow
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = s[i][j] == 'B';
  int tot = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      tot += sum[i][j] =
          (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]) & 1;
  maxflow::Build();
  int mf = maxflow::MaxFlow();
  if (sum[n][m])
    std::cout << tot - mf - (mf & 1);
  else
    std::cout << tot - mf + (mf & 1);
  return 0;
}
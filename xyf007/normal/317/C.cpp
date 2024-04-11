#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
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
} e[100001];
int n, v, m, E, head[301], a[301], b[301], s;
std::vector<int> v1, v2, g[301][301], tmp;
std::vector<std::tuple<int, int, int>> ans;
bool vis[301];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u) {
  g[s][u] = tmp;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (vis[v]) continue;
    tmp.emplace_back(v);
    vis[v] = true;
    Dfs(v);
    tmp.pop_back();
  }
}
void Transfer(int s, int t, int d) {
  if (s == t || g[s][t].empty()) return;
  int pre = g[s][t][g[s][t].size() - 2], cnt = std::min(a[pre], d);
  ans.emplace_back(pre, t, cnt);
  a[pre] -= cnt;
  a[t] += cnt;
  Transfer(s, pre, d);
  if (cnt < d) {
    ans.emplace_back(pre, t, d - cnt);
    a[pre] -= d - cnt;
    a[t] += d - cnt;
  }
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, v, m);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= n; i++) Read(b[i]);
  if (std::accumulate(a + 1, a + n + 1, 0LL) !=
      std::accumulate(b + 1, b + n + 1, 0LL)) {
    std::printf("NO");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    Read(u, v);
    Add(u, v);
    Add(v, u);
  }
  for (int i = 1; i <= n; i++)
    if (a[i] > b[i])
      v1.emplace_back(i);
    else if (a[i] < b[i])
      v2.emplace_back(i);
  for (s = 1; s <= n; s++) {
    std::memset(vis, false, sizeof(vis));
    tmp.emplace_back(s);
    vis[s] = true;
    Dfs(s);
    tmp.pop_back();
  }
  std::size_t p1 = 0, p2 = 0;
  while (p1 < v1.size() && p2 < v2.size())
    if (a[v1[p1]] - b[v1[p1]] == b[v2[p2]] - a[v2[p2]]) {
      int d = a[v1[p1]] - b[v1[p1]];
      Transfer(v1[p1++], v2[p2++], d);
    } else if (a[v1[p1]] - b[v1[p1]] < b[v2[p2]] - a[v2[p2]]) {
      int d = a[v1[p1]] - b[v1[p1]];
      Transfer(v1[p1++], v2[p2], d);
    } else {
      int d = b[v2[p2]] - a[v2[p2]];
      Transfer(v1[p1], v2[p2++], d);
    }
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) {
      std::printf("NO");
      return 0;
    }
  std::printf("%d\n", static_cast<int>(ans.size()));
  for (auto &&i : ans)
    std::printf("%d %d %d\n", std::get<0>(i), std::get<1>(i), std::get<2>(i));
  return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
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
  int to, nxt, cost;
} e[200001];
int n, m, q, E, head[200001], dfn[200001], low[200001], tot, col[200001], c,
    s[200001], top;
std::vector<int> a[200001];
bool vis[200001];
long long dis[200001], g[200001], gcd;
void Add(int f, int t, int c) {
  e[E].to = t;
  e[E].cost = c;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  s[++top] = u;
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (!dfn[v]) {
      Tarjan(v);
      checkmin(low[u], low[v]);
    } else if (vis[v]) {
      checkmin(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    a[col[u] = ++c].emplace_back(u);
    vis[u] = false;
    while (s[top] != u) {
      col[s[top]] = c;
      vis[s[top]] = false;
      a[c].emplace_back(s[top--]);
    }
    top--;
  }
}
void Dfs(int u) {
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (col[v] != col[u]) continue;
    if (!vis[v]) {
      dis[v] = dis[u] + e[i].cost;
      Dfs(v);
    } else {
      gcd = std::__gcd(gcd, dis[u] + e[i].cost - dis[v]);
    }
  }
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    Read(u, v, c);
    Add(u, v, c);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan(i);
  for (int i = 1; i <= c; i++) {
    gcd = 0LL;
    Dfs(a[i][0]);
    g[i] = gcd;
  }
  Read(q);
  while (q--) {
    int u;
    long long s, t;
    Read(u, s, t);
    if (!s) {
      std::printf("YES\n");
      continue;
    }
    if ((t - s) % std::__gcd(g[col[u]], t))
      std::printf("NO\n");
    else
      std::printf("YES\n");
  }
  return 0;
}
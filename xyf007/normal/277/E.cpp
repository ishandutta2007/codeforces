#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
  int to, nxt, flow;
  double cost;
} e[160000];
int n, x[401], y[401], E, head[1001], s, t, ed[1001], flow[1001], le[1001],
    pre[1001];
double dis[1001];
bool vis[1001];
double Dis(int a, int b) { return std::hypot(x[a] - x[b], y[a] - y[b]); }
void Add(int f, int t, double c, int w) {
  e[E].to = t;
  e[E].cost = c;
  e[E].flow = w;
  e[E].nxt = head[f];
  head[f] = E++;
}
bool Spfa() {
  std::fill(dis + 1, dis + t + 1, 1e18);
  std::memset(vis, false, sizeof(vis));
  std::memset(flow, 0, sizeof(flow));
  flow[s] = 1e9;
  pre[t] = -1;
  std::queue<int> q;
  q.emplace(s);
  vis[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].flow && dis[u] + e[i].cost < dis[v]) {
        dis[v] = dis[u] + e[i].cost;
        pre[v] = u;
        flow[v] = std::min(flow[u], e[i].flow);
        le[v] = i;
        if (!vis[v]) {
          q.emplace(v);
          vis[v] = true;
        }
      }
    }
  }
  return ~pre[t];
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n);
  t = 2 * n + 1;
  for (int i = 1; i <= n; i++) {
    Read(x[i], y[i]);
    Add(s, i, 0.0, 2);
    Add(i, s, 0.0, 0);
    ed[i] = E;
    Add(i + n, t, 0.0, 1);
    Add(t, i + n, 0.0, 0);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (y[i] > y[j]) {
        Add(i, n + j, Dis(i, j), 1);
        Add(n + j, i, -Dis(i, j), 0);
      }
  double ans = 0.0;
  while (Spfa()) {
    ans += dis[t] * flow[t];
    int p = t;
    while (p != s) {
      e[le[p]].flow -= flow[t];
      e[le[p] ^ 1].flow += flow[t];
      p = pre[p];
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += e[ed[i]].flow;
  if (sum > 1)
    std::printf("-1");
  else
    std::printf("%.8lf", ans);
  return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <numeric>
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
} e[2000001];
int n, m, E, head[1000001], deg[1000001], dp[1000001], s, t;
bool vis[1000001];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    Read(u, v);
    Add(v, u);
    deg[u]++;
  }
  Read(s, t);
  std::memset(dp, -1, sizeof(dp));
  dp[t] = 0;
  std::deque<int> q;
  q.emplace_back(t);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (!--deg[v]) {
        if (dp[v] == -1 || dp[u] < dp[v]) {
          dp[v] = dp[u];
          q.emplace_front(v);
        }
      } else if (dp[v] == -1) {
        dp[v] = dp[u] + 1;
        q.emplace_back(v);
      }
    }
  }
  std::printf("%d", dp[s]);
  return 0;
}
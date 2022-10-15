#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) {
      return EOF;
    }
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
  }
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) {
    x = y;
  }
}
struct Edge {
  int to, nxt, cost;
} e[400001];
int n, m, E, head[200001], dis[200001], cur[200001], f[200001], ans[200001];
void Add(int f, int t, int c) {
  e[E].to = t;
  e[E].cost = c;
  e[E].nxt = head[f];
  head[f] = E++;
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    Read(u, v, c);
    Add(u, v, c);
    Add(v, u, c);
    f[u] += c;
    f[v] += c;
  }
  std::memset(ans, -1, sizeof(ans));
  for (int i = 2; i < n; i++) {
    f[i] >>= 1;
  }
  std::queue<int> q;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (~ans[i >> 1]) {
        continue;
      }
      ans[i >> 1] = i & 1;
      if (!(f[v] -= e[i].cost)) {
        q.emplace(v);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    std::printf("%d\n", ans[i]);
  }
  return 0;
}
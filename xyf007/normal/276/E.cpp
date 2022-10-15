#include <algorithm>
#include <cstdio>
#include <cstring>
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
  int to, nxt;
} e[200001];
int n, q, E, head[100001], dis[100001], dfn[100001], tot, md[100001], tag;
class FenwickTree {
 public:
  void Add(int x, int v) {
    x++;
    while (x <= n + 1) {
      t_[x] += v;
      x += x & -x;
    }
  }
  int Query(int x) {
    x++;
    int s = 0;
    while (x) {
      s += t_[x];
      x -= x & -x;
    }
    return s;
  }

 private:
  int t_[100001];
} T1;
class FenwickTree2 {
 public:
  void Add(int x, int v) {
    x++;
    while (x) {
      t_[x] += v;
      x -= x & -x;
    }
  }
  int Query(int x) {
    x++;
    int s = 0;
    while (x <= n + 1) {
      s += t_[x];
      x += x & -x;
    }
    return s;
  }

 private:
  int t_[100001];
} T2;
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int fa) {
  dfn[u] = md[u] = ++tot;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dis[v] = dis[u] + 1;
    Dfs(v, u);
    checkmax(md[u], md[v]);
  }
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, q);
  for (int i = 1; i < n; i++) {
    int u, v;
    Read(u, v);
    Add(u, v);
    Add(v, u);
  }
  Dfs(1, 0);
  for (int i = 1; i <= n; i++)
    std::fprintf(stderr, "%d%c", dfn[i], " \n"[i == n]);
  while (q--) {
    int op, u, x, d;
    Read(op, u);
    if (!op) {
      Read(x, d);
      if (u == 1) {
        T2.Add(d, x);
      } else if (dis[u] > d) {
        T1.Add(dfn[u] - d, x);
        T1.Add(std::min(dfn[u] + d, md[u]) + 1, -x);
      } else {
        int tmp = d - dis[u];
        T2.Add(tmp, x);
        T1.Add(std::min(dfn[u] - dis[u] + tmp, md[u]) + 1, x);
        T1.Add(std::min(dfn[u] + d, md[u]) + 1, -x);
      }
    } else {
      std::printf("%d\n", T1.Query(dfn[u]) + T2.Query(dis[u]));
    }
  }
  return 0;
}
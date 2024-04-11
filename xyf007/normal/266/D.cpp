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
int n, m, p[201][201], dis[201][201];
std::vector<std::tuple<int, int, int>> e;
int main(int argc, char const *argv[]) {
  Read(n, m);
  std::memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; i++) {
    dis[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    Read(u, v, c);
    dis[u][v] = dis[v][u] = c;
    e.emplace_back(u, v, c);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        checkmin(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::iota(p[i] + 1, p[i] + n + 1, 1);
      std::sort(p[i] + 1, p[i] + n + 1,
                [&i](const int &lhs, const int &rhs) -> bool {
                  return dis[i][lhs] > dis[i][rhs];
                });
    }
  }
  int ans = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    checkmin(ans, dis[i][p[i][1]] * 2);
  }
  for (auto &&i : e) {
    int u = std::get<0>(i), v = std::get<1>(i), c = std::get<2>(i), t = 1;
    for (int i = 2; i <= n; i++) {
      if (dis[v][p[u][i]] > dis[v][p[u][t]]) {
        checkmin(ans, dis[u][p[u][i]] + dis[v][p[u][t]] + c);
        t = i;
      }
    }
  }
  std::printf("%.11lf", ans / 2.0);
  return 0;
}
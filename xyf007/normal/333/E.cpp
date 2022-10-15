#include <algorithm>
#include <bitset>
#include <cmath>
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
  int u, v;
  double c;
} e[5000001];
int n, x[3001], y[3001], tot;
std::bitset<3001> g[3001];
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(x[i], y[i]);
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      e[++tot] = {i, j, std::hypot(x[i] - x[j], y[i] - y[j])};
  std::sort(e + 1, e + tot + 1, [](const Edge &lhs, const Edge &rhs) -> bool {
    return lhs.c > rhs.c;
  });
  for (int i = 1; i <= tot; i++) {
    int u = e[i].u, v = e[i].v;
    if ((g[u] & g[v]).any()) {
      std::printf("%.8lf", e[i].c / 2);
      return 0;
    }
    g[u].set(v);
    g[v].set(u);
  }
  return 0;
}
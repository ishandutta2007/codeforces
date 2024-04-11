#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
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
int n, m, x, fa[300001];
std::vector<std::pair<int, int>> g[300001];
long long a[300001];
void Init() { std::iota(fa + 1, fa + n + 1, 1); }
int Find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = Find(fa[x]);
}
bool Merge(int x, int y) {
  int fx = Find(x), fy = Find(y);
  if (fx == fy) return false;
  fa[fx] = fy;
  return true;
}
int main(int argc, char const *argv[]) {
  Read(n, m, x);
  for (int i = 1; i <= n; i++) Read(a[i]);
  if (std::accumulate(a + 1, a + n + 1, 0LL) <
      static_cast<long long>(n - 1) * x) {
    std::printf("NO");
    return 0;
  }
  std::printf("YES\n");
  Init();
  for (int i = 1; i <= m; i++) {
    int u, v;
    Read(u, v);
    if (Merge(u, v)) {
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, i);
    }
  }
  Init();
  std::set<std::pair<long long, int>, std::greater<std::pair<long long, int>>>
      s;
  for (int i = 1; i <= n; i++) s.emplace(a[i], i);
  while (s.size() > 1) {
    if (s.begin()->first < x) break;
    int u = s.begin()->second;
    while (true) {
      int v = Find(g[u].back().first);
      if (u == v) {
        g[u].pop_back();
        continue;
      }
      std::printf("%d\n", g[u].back().second);
      g[u].pop_back();
      s.erase(s.begin());
      s.erase({a[v], v});
      if (g[v].size() < g[u].size()) std::swap(u, v);
      a[v] += a[u] - x;
      s.emplace(a[v], v);
      Merge(u, v);
      g[v].insert(g[v].end(), g[u].begin(), g[u].end());
      std::vector<std::pair<int, int>>().swap(g[u]);
      break;
    }
  }
  for (int i = 1; i <= n; i++)
    for (auto &&j : g[i])
      if (Find(i) != Find(j.first)) {
        std::printf("%d\n", j.second);
        Merge(i, j.first);
      }
  return 0;
}
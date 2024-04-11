#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <tuple>
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
int n, sz[5001], sz2[5001], maxp[5001], SZ, rt;
std::tuple<int, int, long long> e[5001];
std::set<std::pair<int, long long>> g[5001];
long long ans = 0x7fffffffffffffff, sum;
void Dfs(int u, int fa) {
  sz[u] = 1;
  for (auto &&i : g[u]) {
    int v = i.first;
    if (v == fa) continue;
    Dfs(v, u);
    sz[u] += sz[v];
  }
}
void GetRoot(int u, int fa) {
  sz2[u] = 1;
  maxp[u] = 0;
  for (auto &&i : g[u]) {
    int v = i.first;
    if (v == fa) continue;
    GetRoot(v, u);
    sz2[u] += sz2[v];
    checkmax(maxp[u], sz2[v]);
  }
  checkmax(maxp[u], SZ - sz2[u]);
  if (!rt || maxp[u] < maxp[rt]) rt = u;
}
void Dfs2(int u, int fa) {
  sz2[u] = 1;
  for (auto &&i : g[u]) {
    int v = i.first;
    if (v == fa) continue;
    Dfs2(v, u);
    sz2[u] += sz2[v];
    sum += sz2[v] * (n - sz2[v]) * i.second;
  }
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    long long c;
    Read(u, v, c);
    e[i] = {u, v, c};
    g[u].emplace(v, c);
    g[v].emplace(u, c);
  }
  Dfs(1, 0);
  for (int i = 1; i < n; i++) {
    int u = std::get<0>(e[i]), v = std::get<1>(e[i]), ru, rv;
    long long c = std::get<2>(e[i]);
    if (sz[u] > sz[v]) std::swap(u, v);
    g[u].erase({v, c});
    g[v].erase({u, c});
    rt = 0;
    SZ = sz[u];
    GetRoot(u, v);
    ru = rt;
    rt = 0;
    SZ = n - SZ;
    GetRoot(v, u);
    rv = rt;
    g[ru].emplace(rv, c);
    g[rv].emplace(ru, c);
    sum = 0LL;
    Dfs2(1, 0);
    checkmin(ans, sum);
    g[ru].erase({rv, c});
    g[rv].erase({ru, c});
    g[u].emplace(v, c);
    g[v].emplace(u, c);
  }
  std::printf("%lld", ans);
  return 0;
}
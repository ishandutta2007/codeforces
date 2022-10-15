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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
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
int n;
long long a[100001], sum, sz[100001], min = 0x7fffffffffffffffLL, lcm = 1;
std::vector<int> g[100001];
long long Lcm(long long x, long long y) { return x / std::__gcd(x, y) * y; }
void Dfs(int u, int fa, long long s) {
  sz[u] = s;
  lcm = Lcm(lcm, s);
  if (g[u].size() == 1) checkmin(min, a[u] * sz[u]);
  if (lcm > min) {
    std::printf("%lld", sum);
    std::exit(0);
  }
  s *= g[u].size() - 1;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u, s);
  }
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  sum = std::accumulate(a + 1, a + n + 1, 0LL);
  for (int i = 1; i < n; i++) {
    int u, v;
    Read(u, v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  g[1].emplace_back(0);
  Dfs(1, 0, 1);
  std::printf("%lld", sum - min / lcm * lcm);
  return 0;
}
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
constexpr int kMod = 1e9 + 7;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int fac[100001], inv[100001];
void Init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = Ksm(fac[n], kMod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
}
int C(int x, int y) {
  if (x < y || y < 0) return 0;
  return mul(fac[x], inv[x - y], inv[y]);
}
int t, n, k, p, cnt[101][101], dep[101], dp[101], ans;
std::vector<int> g[101];
void Dfs(int u, int fa) {
  cnt[p][dep[u] = dep[fa] + 1]++;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u);
  }
}
void Solve(int x) {
  std::memset(dep, 0, sizeof(dep));
  std::vector<int> tmp;
  for (auto &&v : g[x]) {
    p = v;
    std::memset(cnt[v], 0, sizeof(cnt[v]));
    Dfs(v, x);
    tmp.emplace_back(v);
  }
  for (int i = 1; i <= n; i++) {
    std::memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (std::size_t j = 0; j < tmp.size(); j++)
      for (int l = k; l >= 1; l--) Add(dp[l], mul(cnt[tmp[j]][i], dp[l - 1]));
    Add(ans, dp[k]);
  }
}
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, k);
    for (int i = 1; i < n; i++) {
      int u, v;
      Read(u, v);
      g[u].emplace_back(v), g[v].emplace_back(u);
    }
    if (k == 2) {
      std::printf("%d\n", n * (n - 1) / 2);
    } else {
      for (int i = 1; i <= n; i++) Solve(i);
      std::printf("%d\n", ans);
    }
    ans = 0;
    for (int i = 1; i <= n; i++) std::vector<int>().swap(g[i]);
  }
  return 0;
}
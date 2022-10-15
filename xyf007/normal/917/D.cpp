#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 1e9 + 7;
template <typename T>
T add(T a, T b) {
  return a + b >= kMod ? a + b - kMod : a + b;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return a - b < 0 ? a - b + kMod : a - b;
}
template <typename T, typename... Args>
T sub(T a, T b, Args... args) {
  return sub(sub(a, b), args...);
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
  if ((a += b) >= kMod) a -= kMod;
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  if ((a -= b) < 0) a += kMod;
}
template <typename T, typename... Args>
void Sub(T &a, T b, Args... args) {
  Sub(a, add(b, args...));
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
  if (b < 0) a = Ksm(a, kMod - 2), b = -b;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int fac[1000001], inv[1000001];
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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, k, sz[101], f[101][101][101], tmp[101][101], dp[101];
std::vector<int> g[101];
void Dfs(int u, int fa) {
  sz[u] = 1, f[u][0][1] = 1;
  for (auto &v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u);
    std::memset(tmp, 0, sizeof(tmp));
    for (int ku = 0; ku < n; ku++)
      for (int su = 1; su <= sz[u]; su++)
        if (f[u][ku][su])
          for (int kv = 0; ku + kv < n; kv++)
            for (int sv = 1; sv <= sz[v]; sv++)
              if (f[v][kv][sv]) {
                if (ku + kv + 1 < n)
                  Add(tmp[ku + kv + 1][su],
                      mul(f[u][ku][su], f[v][kv][sv], sv));
                Add(tmp[ku + kv][su + sv], mul(f[u][ku][su], f[v][kv][sv]));
              }
    std::memcpy(f[u], tmp, sizeof(tmp));
    sz[u] += sz[v];
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  Init(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs(1, 0);
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= n; j++) Add(dp[i], mul(f[1][i][j], j));
  for (int i = 0; i < n; i++) Mul(dp[i], Ksm(n, i - 1));
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) Sub(dp[i], mul(dp[j], C(n - 1 - j, i - j)));
  for (int i = 0; i < n; i++) std::cout << dp[n - i - 1] << ' ';
  return 0;
}
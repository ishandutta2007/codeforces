#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
constexpr int kMod = 998244353;
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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, k, ind[300001], oud[300001], dp[300001];
std::vector<int> a[300001], b[300001];
bool vno[300001], va[300001], vis[300001];
std::unordered_set<int> g[300001], g_dir[300001];
std::queue<int> qno, qa;
auto clear = []() {
  while (!qa.empty()) {
    int u = qa.front();
    qa.pop();
    for (auto &&x : a[u])
      if (!vno[x]) qno.emplace(x), vno[x] = true;
    while (!qno.empty()) {
      int x = qno.front();
      qno.pop();
      for (auto &&aa : b[x])
        if (!va[aa]) qa.emplace(aa), va[aa] = true;
    }
  }
};
void Del(int x) {
  qno.emplace(x), vno[x] = true;
  while (!qno.empty()) {
    int u = qno.front();
    qno.pop();
    for (auto &&aa : b[u])
      if (!va[aa]) qa.emplace(aa), va[aa] = true;
    for (auto &&v : g[u])
      if (!vno[v]) qno.emplace(v), vno[v] = true;
  }
  clear();
}
std::vector<int> link;
void Dfs(int u, int fa) {
  link.emplace_back(u);
  for (auto &&v : g[u])
    if (v != fa) Dfs(v, u);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[i].resize(x);
    for (int j = 0; j < x; j++) std::cin >> a[i][j], b[a[i][j]].emplace_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (auto &&x : a[i]) {
      if (vis[x]) {
        qa.emplace(i), va[i] = true;
        break;
      }
      vis[x] = true;
    }
    for (auto &&x : a[i]) vis[x] = false;
  }
  clear();
  int tot = 0;
  for (int i = 1; i <= n; i++)
    if (!va[i]) a[++tot] = a[i];
  for (int i = 1; i <= k; i++) b[i].clear();
  for (int i = 1; i <= n; i++)
    for (auto &&x : a[i]) b[x].emplace_back(i);
  n = tot;
  for (int i = 1; i <= n; i++)
    for (std::size_t j = 0; j + 1 < a[i].size(); j++) {
      int u = a[i][j], v = a[i][j + 1];
      if (!g_dir[u].count(v)) {
        g_dir[u].emplace(v);
        g[u].emplace(v), g[v].emplace(u), oud[u]++, ind[v]++;
      }
    }
  for (int i = 1; i <= k; i++)
    if (!vno[i] && (ind[i] > 1 || oud[i] > 1)) Del(i);
  std::unordered_map<int, int> mp;
  for (int i = 1; i <= k; i++)
    if (!vno[i] && !ind[i]) {
      Dfs(i, 0);
      mp[link.size()]++;
      link.clear();
    }
  dp[0] = 1;
  for (int i = 1; i <= m; i++)
    for (auto &&[l, c] : mp)
      if (i >= l) Add(dp[i], mul(dp[i - l], c));
  std::cout << dp[m];
  return 0;
}
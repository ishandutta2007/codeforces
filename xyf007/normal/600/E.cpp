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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, a[100001], sz[100001], son[100001], fa[100001], cnt[100001], max;
long long sum, ans[100001];
std::vector<int> g[100001];
void Dfs(int u, int f) {
  sz[u] = 1, fa[u] = f;
  for (auto &&v : g[u]) {
    if (v == f) continue;
    Dfs(v, u), sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void Modify(int u, int val, int bl) {
  if ((cnt[a[u]] += val) > max)
    max = cnt[a[u]], sum = a[u];
  else if (cnt[a[u]] == max)
    sum += a[u];
  for (auto &&v : g[u]) {
    if (v == fa[u] || v == bl) continue;
    Modify(v, val, bl);
  }
}
void Solve(int u, int op) {
  for (auto &&v : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    Solve(v, 0);
  }
  if (son[u]) Solve(son[u], 1);
  Modify(u, 1, son[u]);
  ans[u] = sum;
  if (!op) Modify(u, -1, 0), max = sum = 0;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs(1, 0), Solve(1, 1);
  for (int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
  return 0;
}
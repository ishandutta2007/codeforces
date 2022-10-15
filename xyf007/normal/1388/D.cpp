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
int n, a[200001], b[200001];
long long f[200001];
std::vector<int> g[200001], ans;
void Dfs(int u) {
  f[u] = a[u];
  for (auto &&v : g[u]) Dfs(v), f[u] += std::max(f[v], 0LL);
}
void Dfs2(int u) {
  for (auto &&v : g[u])
    if (f[v] >= 0) Dfs2(v);
  ans.emplace_back(u);
  for (auto &&v : g[u])
    if (f[v] < 0) Dfs2(v);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    if (b[i] > 0) g[b[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; i++)
    if (b[i] == -1) Dfs(i);
  for (int i = 1; i <= n; i++)
    if (b[i] == -1) Dfs2(i);
  std::cout << std::accumulate(f + 1, f + n + 1, 0LL) << '\n';
  for (auto &&i : ans) std::cout << i << ' ';
  return 0;
}
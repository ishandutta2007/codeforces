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
int n, dep[200001], sz[200001];
long long ans, cnt[2];
std::vector<int> g[200001];
void Dfs(int u, int fa) {
  sz[u] = 1;
  dep[u] = dep[fa] + 1;
  cnt[dep[u] & 1]++;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u);
    sz[u] += sz[v], ans += sz[v] * static_cast<long long>(n - sz[v]);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  Dfs(1, 0);
  std::cout << (ans + cnt[0] * cnt[1]) / 2;
  return 0;
}
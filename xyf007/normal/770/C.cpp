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
int n, k, a[100001], col[100001], ind[100001];
std::vector<int> g[100001], g2[100001];
bool vis[100001];
void Dfs(int u) {
  if (col[u] == 2) return;
  col[u] = 1;
  for (auto &&v : g[u]) {
    if (col[v] == 1) {
      std::cout << -1;
      std::exit(0);
    }
    Dfs(v);
  }
  col[u] = 2;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= k; i++) std::cin >> a[i], vis[a[i]] = true;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    g[i].resize(x);
    for (int j = 0; j < x; j++) std::cin >> g[i][j];
  }
  for (int i = 1; i <= n; i++)
    if (vis[i] && !col[i]) Dfs(i);
  std::cout << std::count_if(col + 1, col + n + 1, [](const int &x) {
    return x > 0;
  }) << '\n';
  for (int i = 1; i <= n; i++)
    if (col[i])
      for (auto &&v : g[i]) g2[v].emplace_back(i), ind[i]++;
  std::queue<int> q;
  for (int i = 1; i <= n; i++)
    if (col[i] && !ind[i]) q.emplace(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    std::cout << u << ' ';
    for (auto &&v : g2[u])
      if (!--ind[v]) q.emplace(v);
  }
  return 0;
}
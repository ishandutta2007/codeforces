#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int u, v, id;
} e[200001];
int n, m, k, dep[200001];
long long ans = 1LL;
std::vector<int> g[200001], in[200001];
bool f[200001];
void Dfs(int u) {
  if (u == n + 1) {
    for (int i = 1; i <= m; i++) std::cout << f[i];
    std::cout << '\n';
    if (!--ans) std::exit(0);
    return;
  }
  for (auto &&i : in[u]) {
    f[i] = true;
    Dfs(u + 1);
    f[i] = false;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
    e[i] = {u, v, i};
  }
  std::memset(dep, -1, sizeof(dep));
  dep[1] = 0;
  std::queue<int> q;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &&v : g[u])
      if (dep[v] == -1) {
        dep[v] = dep[u] + 1;
        q.emplace(v);
      }
  }
  for (int i = 1; i <= m; i++) {
    if (dep[e[i].u] > dep[e[i].v]) std::swap(e[i].u, e[i].v);
    if (dep[e[i].v] == dep[e[i].u] + 1) in[e[i].v].emplace_back(e[i].id);
  }
  for (int i = 2; i <= n; i++) {
    ans *= in[i].size();
    if (ans >= k) break;
  }
  if (ans > k) ans = k;
  std::cout << ans << '\n';
  Dfs(2);
  return 0;
}
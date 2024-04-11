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
int n, m;
std::vector<int> g[200001], com;
bool vis[200001];
void Bfs(int s) {
  std::queue<int> q;
  q.emplace(s), vis[s] = true, com.emplace_back(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &&v : g[u])
      if (!vis[v]) q.emplace(v), vis[v] = true, com.emplace_back(v);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      Bfs(i);
      ans += std::all_of(com.begin(), com.end(),
                         [](const int &x) { return g[x].size() == 2; });
      com.clear();
    }
  std::cout << ans;
  return 0;
}
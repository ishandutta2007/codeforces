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
int T, n, k;
std::unordered_set<int> g[400001];
void Solve() {
  std::cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace(v), g[v].emplace(u);
  }
  std::vector<int> leafs;
  for (int i = 1; i <= n; i++)
    if (g[i].size() <= 1) leafs.emplace_back(i);
  int cnt = 0;
  for (int i = 1; i <= k && cnt < n; i++) {
    cnt += leafs.size();
    std::vector<int> nl;
    for (auto &&u : leafs)
      for (auto &&v : g[u]) {
        g[v].erase(u);
        if (g[v].size() == 1) nl.emplace_back(v);
      }
    std::swap(leafs, nl);
  }
  std::cout << n - cnt << '\n';
  for (int i = 1; i <= n; i++) std::unordered_set<int>().swap(g[i]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
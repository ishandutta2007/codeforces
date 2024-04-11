#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <iostream>
#include <vector>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, fe[200001];
std::vector<int> g[200001];
bool ok;
void Dfs(int u, int fa) {
  int cnt[2] = {0, 0};
  for (const auto v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u), cnt[fe[v]]++;
  }
  if (u != 1) cnt[fe[u] = cnt[0] >= cnt[1]]++;
  if (cnt[0] > cnt[1] || cnt[0] + 1 < cnt[1]) ok = false;
}
void Dfs2(int u, int fa) {
  std::vector<int> e[2];
  for (const auto v : g[u]) {
    if (v == fa) {
      e[fe[u]].emplace_back(u);
    } else {
      e[fe[v]].emplace_back(v);
    }
  }
  int rnd = g[u].size(), cur = g[u].size() & 1;
  for (int i = 1; i <= rnd; i++) {
    int x = e[cur].back();
    if (x == u) {
      std::cout << u << ' ' << fa << '\n';
    } else {
      Dfs2(x, u);
    }
    e[cur].pop_back(), cur ^= 1;
  }
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  ok = true;
  Dfs(1, 0);
  if (!ok) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  Dfs2(1, 0);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
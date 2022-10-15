#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, a[200001], b[200001], c[200001], deg[200001];
std::vector<int> g[200001];
void Solve() {
  std::cin >> n;
  std::fill(c + 1, c + n + 1, 0);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) c[a[i]]++;
  int rt = std::max_element(c + 1, c + n + 1) - c;
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= n; i++) std::cin >> b[i];
  std::fill(deg + 1, deg + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (a[i] == rt || b[i] == rt) continue;
    g[b[i]].emplace_back(a[i]), deg[a[i]]++;
  }
  std::queue<int> q;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 0) q.emplace(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (const auto v : g[u])
      if (!--deg[v]) q.emplace(v);
  }
  std::cout << (*std::max_element(deg + 1, deg + n + 1) ? "WA" : "AC") << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
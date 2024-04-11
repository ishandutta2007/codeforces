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
struct Edge {
  int u, v, c;
  Edge(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}
} e[101];
int n, E, s, m, a[51], f[51][101][51];
std::vector<int> g[51];
void Dfs(int u, int fa) {
  for (auto &&i : g[u]) {
    auto [u, v, c] = e[i];
    if (v == fa) continue;
    Dfs(v, u);
    a[u] += a[v];
  }
}
void Solve(int i, int j);
int Dp(int i, int j, int k) {
  if (!i) return 0;
  if (!f[i][j][k]) Solve(i, j);
  return f[i][j][k];
}
struct Node {
  int i, j, c;
  Node(int i = 0, int j = 0, int c = 0) : i(i), j(j), c(c) {}
  int val() const { return c < i ? Dp(i, j, c + 1) : 0; }
  bool operator<(const Node &rhs) const { return val() < rhs.val(); }
};
void Solve(int i, int j) {
  f[i][j][0] = 0x3f3f3f3f;
  int v = e[j].v, c = e[j].c;
  if (g[v].size() == 1) {
    for (int k = 1; k <= i; k++) f[i][j][k] = Dp(i - k, j ^ 1, i - k) + c;
    return;
  }
  std::priority_queue<Node> q;
  for (auto &&ee : g[v])
    if (ee != (j ^ 1)) q.emplace(i, ee, 0);
  for (int k = 1; k <= i; k++) {
    Node x = q.top();
    q.pop();
    f[i][j][k] = x.val() + c;
    x.c++, q.emplace(x);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    e[E] = {u, v, c}, g[u].emplace_back(E++);
    e[E] = {v, u, c}, g[v].emplace_back(E++);
  }
  std::cin >> s >> m;
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x, a[x]++;
  }
  int ans = 0x3f3f3f3f;
  for (auto &&i : g[s]) Dfs(e[i].v, s), checkmin(ans, Dp(m, i, a[e[i].v]));
  std::cout << ans;
  return 0;
}
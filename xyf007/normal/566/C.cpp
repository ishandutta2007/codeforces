#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
struct Edge {
  int to, nxt, cost;
} e[400001];
int n, a[200001], E, head[200001], sz[200001], SZ, maxp[200001], rt, sol;
bool vis[200001];
double ans = 1e20, cur, sum, s[200001];
void Add(int f, int t, int c) { e[E] = {t, head[f], c}, head[f] = E++; }
void GetRoot(int u, int fa) {
  sz[u] = 1, maxp[u] = 0;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || vis[v]) continue;
    GetRoot(v, u), sz[u] += sz[v], checkmax(maxp[u], sz[v]);
  }
  checkmax(maxp[u], SZ - sz[u]);
  if (!rt || maxp[u] < maxp[rt]) rt = u;
}
void Dfs(int u, int fa, int r, int d) {
  double dd = a[u] * std::sqrt(d);
  cur += dd * d, sum += dd, s[r] += dd;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    Dfs(v, u, r, d + e[i].cost);
  }
}
void Solve(int u) {
  if (vis[u]) return;
  vis[u] = true;
  cur = sum = 0.0;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    s[v] = 0.0, Dfs(v, u, v, e[i].cost);
  }
  if (cur < ans) ans = cur, sol = u;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (sum < 2 * s[v]) {
      rt = 0, SZ = sz[v];
      GetRoot(v, u);
      return Solve(rt);
    }
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::fill(head + 1, head + n + 1, -1);
  for (int i = 1; i < n; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    Add(u, v, c), Add(v, u, c);
  }
  SZ = n;
  GetRoot(1, 0), Solve(rt);
  std::cout << sol << ' ' << std::setprecision(8) << std::fixed << ans;
  return 0;
}
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int to, nxt, cost;
} e[200001];
int n, q, E, head[100001], dep[100001];
class Tree {
 public:
  Tree() {}
  void Build(int rt) {
    Dfs(rt, 0), Dfs2(rt, rt);
    std::vector<std::pair<int, int>> l;
    for (int i = 1; i <= n; i++)
      if (top_[i] == i) l.emplace_back(len_[i], i);
    std::sort(l.begin(), l.end(), std::greater());
    lf_ = l.size();
    std::fill(tm_ + 1, tm_ + n + 1, 0x3f3f3f3f);
    for (int i = 1; i <= lf_; i++) {
      f_[i] = f_[i - 1] + l[i - 1].first;
      for (int j = l[i - 1].second; j; j = son_[j]) tm_[j] = i;
    }
    for (int i = 1; i <= n; i++) ff_[i][0] = fa_[i];
    for (int i = 1; i <= 17; i++)
      for (int j = 1; j <= n; j++) ff_[j][i] = ff_[ff_[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++) g_[i][0] = tm_[fa_[i]];
    for (int i = 1; i <= 17; i++)
      for (int j = 1; j <= n; j++)
        g_[j][i] = std::min(g_[j][i - 1], g_[ff_[j][i - 1]][i - 1]);
    Dfs3(rt, 0);
  }
  int Query(int x, int y) {
    if (tm_[x] <= 2 * y - 1) return f_[std::min(2 * y - 1, lf_)];
    int u = x;
    for (int i = 17; i >= 0; i--)
      if (g_[u][i] > 2 * y - 1) u = ff_[u][i];
    u = ff_[u][0];
    return std::max(f_[2 * y - 2] + max_[x] - dep_[u],
                    f_[2 * y - 1] - max_[u] + max_[x]);
  }
  ~Tree() {}

 private:
  int len_[100001], son_[100001], fa_[100001], top_[100001], w_[100001], lf_,
      f_[100001], tm_[100001], ff_[100001][18], g_[100001][18], dep_[100001],
      max_[100001];
  void Dfs(int u, int fa) {
    fa_[u] = fa;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (v == fa) continue;
      w_[v] = e[i].cost, Dfs(v, u);
      if (len_[v] > len_[son_[u]]) son_[u] = v;
    }
    len_[u] = len_[son_[u]] + w_[u];
  }
  void Dfs2(int u, int t) {
    top_[u] = t;
    if (son_[u]) Dfs2(son_[u], t);
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (v == fa_[u] || v == son_[u]) continue;
      Dfs2(v, v);
    }
  }
  void Dfs3(int u, int fa) {
    max_[u] = dep_[u];
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (v == fa) continue;
      dep_[v] = dep_[u] + e[i].cost, Dfs3(v, u);
      checkmax(max_[u], max_[v]);
    }
  }
} t[2];
void Add(int f, int t, int c) { e[E] = {t, head[f], c}, head[f] = E++; }
void Dfs(int u, int fa) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dep[v] = dep[u] + e[i].cost, Dfs(v, u);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  std::fill(head + 1, head + n + 1, -1);
  for (int i = 1; i < n; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    Add(u, v, c), Add(v, u, c);
  }
  Dfs(1, 0);
  int x = std::max_element(dep + 1, dep + n + 1) - dep;
  dep[x] = 0, Dfs(x, 0);
  int y = std::max_element(dep + 1, dep + n + 1) - dep;
  t[0].Build(x), t[1].Build(y);
  int ans = 0;
  while (q--) {
    int x, y;
    std::cin >> x >> y, x = (x + ans - 1) % n + 1, y = (y + ans - 1) % n + 1;
    std::cout << (ans = std::max(t[0].Query(x, y), t[1].Query(x, y))) << '\n';
  }
  return 0;
}
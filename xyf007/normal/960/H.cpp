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
struct Node {
  int ls, rs;
  long long s1, s2, tag;
} t[10000001];
int n, m, q, a[50001], b[50001], fa[50001], sz[50001], son[50001], dep[50001],
    top[50001], dfn[50001], tot, root[50001], cnt;
long long c, ans[50001], s1[50001], s2[50001];
std::vector<int> g[50001];
void Dfs(int u) {
  sz[u] = 1;
  for (auto &&v : g[u]) {
    dep[v] = dep[u] + 1, Dfs(v), sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void Dfs(int u, int t) {
  top[u] = t, dfn[u] = ++tot;
  if (son[u]) Dfs(son[u], t);
  for (auto &&v : g[u]) {
    if (v == son[u]) continue;
    Dfs(v, v);
  }
}
void Pushup(int x) {
  t[x].s1 = t[t[x].ls].s1 + t[t[x].rs].s1;
  t[x].s2 = t[t[x].ls].s2 + t[t[x].rs].s2;
}
void Add(int l, int r, int v, int x) {
  t[x].s2 += 2 * v * t[x].s1 + (r - l + 1) * v * v;
  t[x].s1 += (r - l + 1) * v;
  t[x].tag += v;
}
void Pushdown(int l, int r, int x) {
  if (t[x].tag) {
    int mid = (l + r) >> 1;
    if (!t[x].ls) t[x].ls = ++cnt;
    Add(l, mid, t[x].tag, t[x].ls);
    if (!t[x].rs) t[x].rs = ++cnt;
    Add(mid + 1, r, t[x].tag, t[x].rs);
    t[x].tag = 0LL;
  }
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    Add(l, r, v, x);
    return;
  }
  Pushdown(l, r, x);
  int mid = (l + r) >> 1;
  if (L <= mid) {
    if (!t[x].ls) t[x].ls = ++cnt;
    Modify(L, R, l, mid, v, t[x].ls);
  }
  if (R > mid) {
    if (!t[x].rs) t[x].rs = ++cnt;
    Modify(L, R, mid + 1, r, v, t[x].rs);
  }
  Pushup(x);
}
template <typename T1, typename T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2> &lhs,
                            const std::pair<T1, T2> &rhs) {
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}
template <typename T1, typename T2>
std::pair<T1, T2> &operator+=(std::pair<T1, T2> &lhs,
                              const std::pair<T1, T2> &rhs) {
  return lhs = lhs + rhs;
}
std::pair<long long, long long> Query(int L, int R, int l, int r, int x) {
  if (!x) return {0LL, 0LL};
  if (L <= l && r <= R) return {t[x].s1, t[x].s2};
  Pushdown(l, r, x);
  int mid = (l + r) >> 1;
  std::pair<long long, long long> ans;
  if (L <= mid) ans += Query(L, R, l, mid, t[x].ls);
  if (R > mid) ans += Query(L, R, mid + 1, r, t[x].rs);
  return ans;
}
void Modify(int u, int op) {
  int c = a[u];
  while (u) {
    std::pair<long long, long long> pre = Query(dfn[top[u]], dfn[u], 1, n,
                                                root[c]),
                                    suf;
    Modify(dfn[top[u]], dfn[u], 1, n, op, root[c]);
    suf = Query(dfn[top[u]], dfn[u], 1, n, root[c]);
    s1[c] += suf.first - pre.first, s2[c] += suf.second - pre.second;
    u = fa[top[u]];
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q >> c;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 2; i <= n; i++) std::cin >> fa[i], g[fa[i]].emplace_back(i);
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  Dfs(1), Dfs(1, 1);
  std::iota(root + 1, root + m + 1, 1), cnt = m;
  for (int i = 1; i <= n; i++) Modify(i, 1);
  while (q--) {
    int op, x;
    std::cin >> op >> x;
    if (op == 1) {
      int y;
      std::cin >> y;
      Modify(x, -1), a[x] = y, Modify(x, 1);
    } else {
      std::cout << std::setprecision(8) << std::fixed
                << static_cast<double>(n * c * c - 2 * c * b[x] * s1[x] +
                                       b[x] * b[x] * s2[x]) /
                       n
                << '\n';
    }
  }
  return 0;
}
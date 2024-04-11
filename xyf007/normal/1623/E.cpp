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
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int n, k, ls[200001], rs[200001], seq[200001], tot, nxt[200001], sz[200001],
    fa[200001], son[200001], dfn[200001], top[200001], c1[800001], c2[800001],
    tag[800001], rev[200001];
std::vector<int> g[200001];
char s[200005];
bool vis[200001];
void Dfs(int u) {
  if (u == 0) return;
  Dfs(ls[u]), seq[++tot] = u, Dfs(rs[u]);
}
void Dfs2(int u) {
  sz[u] = 1;
  for (const auto &v : g[u]) {
    fa[v] = u, Dfs2(v), sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void Dfs(int u, int t) {
  rev[dfn[u] = ++tot] = u, top[u] = t;
  if (son[u]) Dfs(son[u], t);
  for (const auto &v : g[u]) {
    if (v == son[u]) continue;
    Dfs(v, v);
  }
}
void Pushup(int x) {
  c1[x] = c1[x + x] + c1[x + x + 1], c2[x] = c2[x + x] + c2[x + x + 1];
}
void Pushdown(int x) {
  if (tag[x]) {
    c2[x + x] = c2[x + x + 1] = 0;
    tag[x + x] = tag[x + x + 1] = 1;
    tag[x] = 0;
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    c2[x] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) {
    c2[x] = 0, tag[x] = 1;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int l, int r, int p, int x) {
  if (l == r) {
    c1[x] = 1;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify(l, mid, p, x + x);
  else
    Modify(mid + 1, r, p, x + x + 1);
  Pushup(x);
}
std::pair<int, int> operator+(const std::pair<int, int> &lhs,
                              const std::pair<int, int> &rhs) {
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}
std::pair<int, int> &operator+=(std::pair<int, int> &lhs,
                                const std::pair<int, int> &rhs) {
  lhs.first += rhs.first, lhs.second += rhs.second;
  return lhs;
}
std::pair<int, int> Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return {c1[x], c2[x]};
  Pushdown(x);
  int mid = (l + r) >> 1;
  std::pair<int, int> ans;
  if (L <= mid) ans += Query(L, R, l, mid, x + x);
  if (R > mid) ans += Query(L, R, mid + 1, r, x + x + 1);
  return ans;
}
std::pair<int, int> Query(int u) {
  std::pair<int, int> ans;
  while (u) {
    ans += Query(dfn[top[u]], dfn[u], 1, n, 1);
    u = fa[top[u]];
  }
  return ans;
}
bool Check(int l, int r, int p, int x) {
  if (l == r) return c2[x] == 0;
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid)
    return Check(l, mid, p, x + x);
  else
    return Check(mid + 1, r, p, x + x + 1);
}
void Work(int u) {
  while (u) {
    Modify(dfn[top[u]], dfn[u], 1, n, 1);
    u = fa[top[u]];
  }
}
void DfsTree(int l, int r, int x) {
  if (l == r) {
    vis[rev[l]] = c2[x] == 0;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  DfsTree(l, mid, x + x), DfsTree(mid + 1, r, x + x + 1);
}
void Solve(int u) {
  if (u == 0) return;
  Solve(ls[u]);
  std::cout << s[u];
  if (vis[u]) std::cout << s[u];
  Solve(rs[u]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k >> (s + 1);
  for (int i = 1; i <= n; i++) std::cin >> ls[i] >> rs[i];
  Dfs(1);
  tot = 0;
  nxt[n] = n + 1;
  for (int i = n - 1; i >= 1; i--)
    nxt[i] = s[seq[i]] == s[seq[i + 1]] ? nxt[i + 1] : i + 1;
  for (int i = 1; i <= n; i++) {
    if (ls[i]) g[i].push_back(ls[i]);
    if (rs[i]) g[i].push_back(rs[i]);
  }
  Dfs2(1), Dfs(1, 1);
  Build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    int u = seq[i];
    if (Check(1, n, dfn[u], 1)) continue;
    if (nxt[i] > n || s[seq[nxt[i]]] < s[u]) {
      Modify(1, n, dfn[u], 1);
      continue;
    }
    auto [bl, cnt] = Query(u);
    if (bl || cnt > k) continue;
    Work(u);
    k -= cnt;
  }
  DfsTree(1, n, 1);
  Solve(1);
  return 0;
}
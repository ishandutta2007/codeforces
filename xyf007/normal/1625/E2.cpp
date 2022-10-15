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
int n, q, s[300005], a[300005], tot, stk[300005], top, nxt[300005], rev[300005],
    fa[300005], dfn[300005], b[300005], out[300005], cnt, id[300005];
long long v[300005], sz[300005];
char ss[300005];
std::vector<int> p[300005], g[300005];
bool ok[300005];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 0) : n_(n) { t_.resize(n + 1); }
  void Init(int n) { n_ = n, t_.resize(n + 1); }
  void Add(int x, const T &v) {
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  T Query(int x) {
    T s(0);
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::vector<T>(n_ + 1, 0).swap(t_); }
  ~FenwickTree() {}

 private:
  int n_;
  std::vector<T> t_;
};
FenwickTree<int> bit[300005];
void Add(int l, int r, int k, int u) {
  l = rev[l], r = rev[r] - 1;
  for (int i = l; i <= r; i++) g[u].push_back(p[k][i]), fa[p[k][i]] = u;
}
void Dfs(int u) {
  b[dfn[u] = ++cnt] = u, sz[u] = g[u].size();
  v[u] = 1 + sz[u] * (sz[u] - 1) / 2;
  int now = 0;
  for (const auto &v : g[u]) Dfs(v), id[v] = ++now;
  bit[u].Init(sz[u]);
  out[u] = cnt;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q >> (ss + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (ss[i] == '(' ? 1 : -1);
  std::memcpy(a + 1, s, 4 * (n + 1)), tot = n + 1;
  std::sort(a + 1, a + tot + 1);
  tot = std::unique(a + 1, a + tot + 1) - a - 1;
  for (int i = 0; i <= n; i++)
    p[std::lower_bound(a + 1, a + tot + 1, s[i]) - a].push_back(i);
  for (int i = 0; i <= n; i++) {
    while (top && s[i] < s[stk[top]]) nxt[stk[top--]] = i;
    stk[++top] = i;
  }
  while (top) nxt[stk[top--]] = n + 1;
  for (int i = 1; i <= tot; i++)
    for (std::size_t j = 0; j < p[i].size(); j++) rev[p[i][j]] = j;
  std::memset(fa, -1, sizeof(fa));
  for (int i = tot; i >= 1; i--) {
    for (std::size_t j = 0; j + 1 < p[i].size(); j++) {
      int x = p[i][j], y = p[i][j + 1];
      if (nxt[x] <= y) continue;
      ok[x] = true;
      if (y != x + 2)
        Add(x + 1, y - 1, i + 1, x);
      else
        v[x] = 1LL;
    }
  }
  for (int i = 0; i <= n; i++)
    if (ok[i] && fa[i] == -1) g[n + 1].push_back(i), fa[i] = n + 1;
  Dfs(n + 1);
  FenwickTree<long long> T(cnt);
  for (int i = 1; i <= cnt; i++) T.Add(i, v[b[i]]);
  while (q--) {
    int op, l, r;
    std::cin >> op >> l >> r, l--;
    if (op == 1) {
      T.Add(dfn[l], -1LL);
      int f = fa[l];
      bit[f].Add(id[l], 1);
      T.Add(dfn[f], -(--sz[f]));
    } else {
      int x = l, y = rev[r] - 1, f = fa[l],
          k = std::lower_bound(a + 1, a + tot + 1, s[r]) - a;
      y = p[k][y];
      long long son = bit[f].Query(id[y]) - bit[f].Query(id[x] - 1);
      son = rev[r] - rev[l] - son;
      std::cout << T.Query(out[y]) - T.Query(dfn[x] - 1) + son * (son - 1) / 2
                << '\n';
    }
  }
  return 0;
}
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
  int ls, rs, max;
} t[4000001];
struct Q {
  int l, r, id;
} b[300001];
int n, m, a[100001], tot, root = 1, ans[300001];
void Pushup(int x) { t[x].max = std::max(t[t[x].ls].max, t[t[x].rs].max); }
int Modify(int l, int r, int p, int v, int x) {
  int xx = ++tot;
  t[xx] = t[x];
  if (l == r) {
    t[xx].max = v;
    return xx;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    t[xx].ls = Modify(l, mid, p, v, t[x].ls);
  else
    t[xx].rs = Modify(mid + 1, r, p, v, t[x].rs);
  Pushup(xx);
  return xx;
}
int Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return t[x].max;
  int mid = (l + r) >> 1;
  if (R <= mid)
    return Query(L, R, l, mid, t[x].ls);
  else if (L > mid)
    return Query(L, R, mid + 1, r, t[x].rs);
  else
    return std::max(Query(L, R, l, mid, t[x].ls),
                    Query(L, R, mid + 1, r, t[x].rs));
}
class FenwickTree {
 public:
  FenwickTree() { std::memset(t_, 0x3f, sizeof(t_)); }
  void Add(int x, int v) {
    while (x) checkmin(t_[x], v), x -= x & -x;
  }
  int Query(int x) {
    int s = 0x3f3f3f3f;
    while (x <= n) checkmin(s, t_[x]), x += x & -x;
    return s;
  }
  ~FenwickTree() {}

 private:
  int t_[100001];
} T;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::cin >> m;
  for (int i = 1; i <= m; i++) std::cin >> b[i].l >> b[i].r, b[i].id = i;
  std::sort(b + 1, b + m + 1,
            [](const Q &lhs, const Q &rhs) { return lhs.r < rhs.r; });
  int p = 0;
  for (int i = 1; i <= m; i++) {
    while (p < b[i].r) {
      p++;
      int pos = Query(a[p], 1e9, 0, 1e9, root), v = a[pos];
      while (pos) {
        T.Add(pos, v - a[p]);
        int nv = (v + a[p]) >> 1, np = Query(a[p], nv, 0, 1e9, root);
        if (np == pos) break;
        pos = np, v = a[pos];
      }
      pos = Query(0, a[p], 0, 1e9, root), v = a[pos];
      while (pos) {
        T.Add(pos, a[p] - v);
        int nv = (a[p] + v + 1) >> 1, np = Query(nv, a[p], 0, 1e9, root);
        if (np == pos) break;
        pos = np, v = a[pos];
      }
      root = Modify(0, 1e9, a[p], p, root);
    }
    ans[b[i].id] = T.Query(b[i].l);
  }
  for (int i = 1; i <= m; i++) std::cout << ans[i] << '\n';
  return 0;
}
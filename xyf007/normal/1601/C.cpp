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
int T, n, m, a[1000001], b[1000001], c[1000001], d[1000001], min[4000001],
    tag[4000001], p[1000001];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) {}
  void Init(int n) { n_ = n; }
  void Add(int x, const T &v) {
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  T Query(int x) {
    T s(0);
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::memset(t_ + 1, 0, sizeof(T) * n_); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[1000001];
};
void Pushup(int x) { min[x] = std::min(min[x + x], min[x + x + 1]); }
void Pushdown(int x) {
  if (tag[x]) {
    min[x + x] += tag[x], tag[x + x] += tag[x];
    min[x + x + 1] += tag[x], tag[x + x + 1] += tag[x];
    tag[x] = 0;
  }
}
void Build(int l, int r, int x) {
  tag[x] = min[x] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    min[x] += v, tag[x] += v;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, v, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
  Pushup(x);
}
int Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return min[x];
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (R <= mid) return Query(L, R, l, mid, x + x);
  if (L > mid) return Query(L, R, mid + 1, r, x + x + 1);
  return std::min(Query(L, R, l, mid, x + x),
                  Query(L, R, mid + 1, r, x + x + 1));
}
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memcpy(c + 1, a + 1, 4 * n);
  std::iota(p + 1, p + n + 1, 1);
  std::sort(p + 1, p + n + 1,
            [](const int &lhs, const int &rhs) { return a[lhs] < a[rhs]; });
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  std::sort(b + 1, b + m + 1);
  std::memcpy(d + 1, c + 1, 4 * n);
  std::sort(d + 1, d + n + 1);
  int nn = std::unique(d + 1, d + n + 1) - d - 1;
  for (int i = 1; i <= n; i++)
    c[i] = std::lower_bound(d + 1, d + nn + 1, c[i]) - d;
  FenwickTree bit(nn);
  bit.Clear();
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    ans += i - 1 - bit.Query(c[i]);
    bit.Add(c[i], 1);
  }
  std::sort(a + 1, a + n + 1);
  Build(1, n + 1, 1);
  for (int i = 1; i <= n; i++) Modify(i + 1, n + 1, 1, n + 1, 1, 1);
  int l1 = 1, l2 = 1;
  for (int i = 1; i <= m; i++) {
    while (l1 <= n && b[i] >= a[l1])
      Modify(p[l1++] + 1, n + 1, 1, n + 1, -1, 1);
    while (l2 <= n && b[i] > a[l2]) Modify(1, p[l2++], 1, n + 1, 1, 1);
    ans += min[1];
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
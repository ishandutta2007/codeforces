#include <algorithm>
#include <cstring>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, a[150001], b[150001];
long long ans[150001];
struct Node {
  int max, smax, c1, c2, ta, tm;
  long long sum;
} t[600001];
void Pushup(int x) {
  t[x].sum = t[x + x].sum + t[x + x + 1].sum;
  t[x].max = std::max(t[x + x].max, t[x + x + 1].max);
  if (t[x + x].max == t[x + x + 1].max) {
    t[x].smax = std::max(t[x + x].smax, t[x + x + 1].smax);
    t[x].c1 = t[x + x].c1 + t[x + x + 1].c1;
    t[x].c2 = t[x + x].c2 + t[x + x + 1].c2;
  } else if (t[x + x].max > t[x + x + 1].max) {
    t[x].smax = std::max(t[x + x].smax, t[x + x + 1].max);
    t[x].c1 = t[x + x].c1;
    t[x].c2 = t[x + x + 1].c1 + t[x + x].c2 + t[x + x + 1].c2;
  } else {
    t[x].smax = std::max(t[x + x].max, t[x + x + 1].smax);
    t[x].c1 = t[x + x + 1].c1;
    t[x].c2 = t[x + x].c1 + t[x + x].c2 + t[x + x + 1].c2;
  }
}
void Add(int v, int x) {
  t[x].max += v, t[x].smax += v;
  t[x].sum += static_cast<long long>(t[x].c1 + t[x].c2) * v;
  t[x].ta += v;
  if (t[x].tm != -1) t[x].tm += v;
}
void Min(int v, int x) {
  t[x].sum -= (t[x].max - v) * t[x].c1, t[x].max = t[x].tm = v;
}
void Pushdown(int x) {
  if (t[x].ta) {
    Add(t[x].ta, x + x), Add(t[x].ta, x + x + 1);
    t[x].ta = 0;
  }
  if (t[x].tm != -1) {
    if (t[x].tm < t[x + x].max) Min(t[x].tm, x + x);
    if (t[x].tm < t[x + x + 1].max) Min(t[x].tm, x + x + 1);
    t[x].tm = -1;
  }
}
void Build(int l, int r, int x) {
  t[x] = {0, -0x3f3f3f3f, 0, 0, 0, -1, 0LL};
  if (l == r) return;
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int l, int r, int p, int v, int x) {
  if (l == r) {
    t[x].max = t[x].sum = v, t[x].c1 = 1;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify(l, mid, p, v, x + x);
  else
    Modify(mid + 1, r, p, v, x + x + 1);
  Pushup(x);
}
void Add(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) return Add(v, x);
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Add(L, R, l, mid, v, x + x);
  if (R > mid) Add(L, R, mid + 1, r, v, x + x + 1);
  Pushup(x);
}
void Min(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    if (t[x].max <= v) return;
    if (t[x].smax < v) return Min(v, x);
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Min(L, R, l, mid, v, x + x);
  if (R > mid) Min(L, R, mid + 1, r, v, x + x + 1);
  Pushup(x);
}
long long Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return t[x].sum;
  Pushdown(x);
  int mid = (l + r) >> 1;
  long long ans = 0LL;
  if (L <= mid) ans += Query(L, R, l, mid, x + x);
  if (R > mid) ans += Query(L, R, mid + 1, r, x + x + 1);
  return ans;
}
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
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
  T t_[150001];
};
void Solve() {
  for (int i = 1; i <= n; i++) b[a[i]] = i;
  Build(1, n, 1);
  FenwickTree bit(n);
  for (int i = 1; i <= n; i++) {
    Modify(1, n, b[i], i + 1, 1);
    bit.Add(b[i], 1);
    if (b[i] > 1) Min(1, b[i] - 1, 1, n, bit.Query(b[i]), 1);
    if (b[i] < n) Add(b[i] + 1, n, 1, n, 1, 1);
    ans[i] += t[1].sum;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  Solve();
  std::reverse(a + 1, a + n + 1);
  Solve();
  for (int i = 1; i <= n; i++)
    std::cout << ans[i] - i * static_cast<long long>(i + 2) << '\n';
  return 0;
}
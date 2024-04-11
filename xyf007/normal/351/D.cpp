#include <algorithm>
#include <array>
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
struct Node {
  int l, r;
} b[100001];
int n, m, a[100001], la[100001], pre[100001], ans[100001], L[100001],
    min[400001];
std::vector<std::array<int, 3>> d[100001];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
  void Add(int x, const T &v) {
    x++;
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  T Query(int x) {
    x++;
    T s(0);
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::memset(t_ + 1, 0, sizeof(T) * n_); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[100010];
};
FenwickTree bit(100005);
std::vector<int> q[100001];
void Pushup(int x) { min[x] = std::min(min[x + x], min[x + x + 1]); }
void Modify(int l, int r, int p, int v, int x) {
  if (l == r) {
    min[x] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify(l, mid, p, v, x + x);
  else
    Modify(mid + 1, r, p, v, x + x + 1);
  Pushup(x);
}
int Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return min[x];
  int mid = (l + r) >> 1, ans = n + 1;
  if (L <= mid) checkmin(ans, Query(L, R, l, mid, x + x));
  if (R > mid) checkmin(ans, Query(L, R, mid + 1, r, x + x + 1));
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) pre[i] = std::exchange(la[a[i]], i);
  std::cin >> m;
  for (int i = 1; i <= m; i++) std::cin >> b[i].l >> b[i].r;
  for (int i = 1; i <= m; i++) {
    d[b[i].l - 1].push_back({b[i].l - 1, i, -1});
    d[b[i].r].push_back({b[i].l - 1, i, 1});
  }
  for (int i = 1; i <= m; i++) q[b[i].r].push_back(i);
  for (int i = 1; i <= n; i++) {
    bit.Add(pre[i], 1);
    for (const auto &[x, id, op] : d[i]) ans[id] += op * bit.Query(x);
  }
  for (int i = 1; i <= n; i++)
    if (!pre[pre[i]] || i - pre[i] == pre[i] - pre[pre[i]])
      L[i] = L[pre[i]];
    else
      L[i] = pre[pre[i]];
  for (int i = 1; i <= n; i++) {
    if (pre[i]) Modify(1, n, pre[i], n + 1, 1);
    Modify(1, n, i, L[i], 1);
    for (const auto &j : q[i])
      ans[j] += Query(b[j].l, b[j].r, 1, n, 1) >= b[j].l;
  }
  for (int i = 1; i <= m; i++) std::cout << ans[i] << '\n';
  return 0;
}
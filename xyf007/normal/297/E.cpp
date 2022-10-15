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
struct Node {
  int l, r, id;
} a[100001];
int n;
long long l[100001], r[100001];
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
  T t_[200001];
};
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].l >> a[i].r, a[i].id = i;
    if (a[i].l > a[i].r) std::swap(a[i].l, a[i].r);
  }
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.l < rhs.l; });
  FenwickTree bit(2 * n);
  for (int i = 1; i <= n; i++) {
    l[a[i].id] = bit.Query(a[i].l) + i - 1 - bit.Query(a[i].r);
    bit.Add(a[i].r, 1);
  }
  bit.Clear();
  for (int i = n; i >= 1; i--) {
    l[a[i].id] += n - i - bit.Query(a[i].r);
    bit.Add(a[i].l, 1);
  }
  bit.Clear();
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.r < rhs.r; });
  for (int i = 1; i <= n; i++) {
    r[a[i].id] = i - 1 - bit.Query(a[i].l);
    bit.Add(a[i].l, 1);
  }
  long long ans = static_cast<long long>(n) * (n - 1) * (n - 2) / 6, f2 = 0LL;
  for (int i = 1; i <= n; i++)
    ans -= l[i] * r[i], f2 += (l[i] + r[i]) * (n - l[i] - r[i] - 1);
  std::cout << ans - f2 / 2;
  return 0;
}
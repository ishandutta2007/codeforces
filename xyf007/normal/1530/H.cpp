#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <algorithm>
#include <cstdio>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n, a[15001], f[301][15001], g[301][15001];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n + 1) { Clear(); }
  void Init(int n) { n_ = n + 1, Clear(); }
  void Add(int x, const T &v) {
    x++;
    while (x <= n_) checkmax(t_[x], v), x += x & -x;
  }
  T Query(int x) {
    x++;
    T s(0);
    while (x) checkmax(s, t_[x]), x -= x & -x;
    return s;
  }
  void Clear() { std::fill(t_ + 1, t_ + n_ + 1, 0); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[200001];
};
template <typename T = int>
class FenwickTree2 {
 public:
  FenwickTree2(int n = 200000) : n_(n + 1) { Clear(); }
  void Init(int n) { n_ = n + 1, Clear(); }
  void Add(int x, const T &v) {
    x++;
    while (x) checkmin(t_[x], v), x -= x & -x;
  }
  T Query(int x) {
    x++;
    T s(n_ - 1);
    while (x <= n_) checkmin(s, t_[x]), x += x & -x;
    return s;
  }
  void Clear() { std::fill(t_ + 1, t_ + n_ + 1, n_ - 1); }
  ~FenwickTree2() {}

 private:
  int n_;
  T t_[200001];
};
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int m = std::min(300, n);
  for (int i = 1; i <= m; i++) std::fill(f[i] + 1, f[i] + n + 1, 0);
  for (int i = 1; i <= m; i++) std::fill(g[i] + 1, g[i] + n + 1, n + 1);
  f[1][n] = a[n], g[1][n] = a[n];
  FenwickTree bit1(n + 1), bit2(n + 1);
  FenwickTree2 bit3(n + 1), bit4(n + 1);
  for (int k = 2; k <= m; k++) {
    bit1.Clear(), bit2.Clear(), bit3.Clear(), bit4.Clear();
    for (int i = n - 1; i >= 1; i--) {
      bit1.Add(a[i + 1], f[k - 1][i + 1]);
      if (i + k - 1 <= n) bit2.Add(g[k - 1][i + k - 1], a[i + k - 1]);
      f[k][i] = std::max(bit1.Query(a[i]), bit2.Query(a[i]));
      bit3.Add(a[i + 1], g[k - 1][i + 1]);
      if (i + k - 1 <= n) bit4.Add(f[k - 1][i + k - 1], a[i + k - 1]);
      g[k][i] = std::min(bit3.Query(a[i]), bit4.Query(a[i]));
    }
  }
  int ans1 = 0, ans2 = 0;
  for (int i = m; i >= 1; i--)
    if (*std::max_element(f[i] + 1, f[i] + n + 1) ||
        *std::min_element(g[i] + 1, g[i] + n + 1) <= n) {
      ans1 = i;
      break;
    }
  for (int i = 1; i <= m; i++) std::fill(f[i] + 1, f[i] + n + 1, 0);
  for (int i = 1; i <= m; i++) std::fill(g[i] + 1, g[i] + n + 1, n + 1);
  for (int i = 1; i < n; i++) f[2][i] = a[i], g[2][i] = a[i];
  for (int k = 3; k <= m; k++) {
    bit1.Clear(), bit2.Clear(), bit3.Clear(), bit4.Clear();
    for (int i = n - 1; i >= 1; i--) {
      bit1.Add(a[i + 1], f[k - 1][i + 1]);
      if (i + k - 1 <= n) bit2.Add(g[k - 1][i + k - 1], a[i + k - 1]);
      f[k][i] = std::max(bit1.Query(a[i]), bit2.Query(a[i]));
      bit3.Add(a[i + 1], g[k - 1][i + 1]);
      if (i + k - 1 <= n) bit4.Add(f[k - 1][i + k - 1], a[i + k - 1]);
      g[k][i] = std::min(bit3.Query(a[i]), bit4.Query(a[i]));
    }
  }
  for (int i = m; i >= 1; i--)
    if (*std::max_element(f[i] + 1, f[i] + n + 1) ||
        *std::min_element(g[i] + 1, g[i] + n + 1) <= n) {
      ans2 = i - 1;
      break;
    }
  std::cout << std::max(ans1, ans2) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
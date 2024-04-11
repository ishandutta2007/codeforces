#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
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
int n, L[100001], d[100001], nn;
long long k, a[100001], b[100001], min[100001], f[100001], g[100001], c[100002];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 1) : n_(n) { t_.resize(n_ + 1); }
  void Init(int n) { n_ = n, t_.resize(n_ + 1); }
  void Add(int x, const T &v) {
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  T Query(int x) {
    T s(0);
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::fill(t_.begin(), t_.end(), T(0)); }
  ~FenwickTree() {}

 private:
  int n_;
  std::vector<T> t_;
};
template <typename T = std::pair<long long, int>>
class FenwickTree2 {
 public:
  FenwickTree2(int n = 1) : n_(n + 1) { t_.resize(n_ + 1), Clear(); }
  void Init(int n) { n_ = n + 1, t_.resize(n_ + 1), Clear(); }
  void Add(int x, const T &v) {
    x++;
    while (x) checkmax(t_[x], v), x -= x & -x;
  }
  T Query(int x) {
    x++;
    T s(0xc0c0c0c0c0c0c0c0LL, 0);
    while (x <= n_) checkmax(s, t_[x]), x += x & -x;
    return s;
  }
  void Clear() { std::fill(t_.begin(), t_.end(), T(0xc0c0c0c0c0c0c0c0LL, 0)); }
  ~FenwickTree2() {}

 private:
  int n_;
  std::vector<T> t_;
};
template <typename T = std::pair<long long, int>>
class FenwickTree3 {
 public:
  FenwickTree3(int n = 1) : n_(n + 1) { t_.resize(n_ + 1), Clear(); }
  void Init(int n) { n_ = n + 1, t_.resize(n_ + 1), Clear(); }
  void Add(int x, const T &v) {
    x++;
    while (x <= n_) checkmax(t_[x], v), x += x & -x;
  }
  T Query(int x) {
    x++;
    T s(0xc0c0c0c0c0c0c0c0LL, 0);
    while (x) checkmax(s, t_[x]), x -= x & -x;
    return s;
  }
  void Clear() { std::fill(t_.begin(), t_.end(), T(0xc0c0c0c0c0c0c0c0LL, 0)); }
  ~FenwickTree3() {}

 private:
  int n_;
  std::vector<T> t_;
};
long long Check(long long x) {
  std::fill(f + 1, f + n + 1, 0xc0c0c0c0c0c0c0c0LL);
  std::fill(g + 1, g + n + 1, 0);
  FenwickTree cnt(nn);
  FenwickTree<long long> sum(nn);
  cnt.Add(d[0], 1), sum.Add(d[0], b[0]);
  long long F = 0LL, G = 0LL;
  for (int i = 1; i <= n; i++) {
    int p = std::upper_bound(c + 1, c + nn + 1, b[i] - x) - c - 1;
    F += (b[i] - x) * cnt.Query(p) - sum.Query(p), G += cnt.Query(p);
    cnt.Add(d[i], 1), sum.Add(d[i], b[i]);
  }
  FenwickTree2 suf(n);
  FenwickTree3 pre(n);
  suf.Add(0, {0LL, 0}), pre.Add(0, {0LL, 0});
  for (int i = 1; i <= n; i++) {
    int l = 0, r = i;
    L[i] = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (min[mid] <= b[i] - x)
        L[i] = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    auto t1 = suf.Query(L[i]), t2 = pre.Query(L[i] - 1);
    t2.first += b[i] - x, t2.second++;
    std::tie(f[i], g[i]) = std::max(t1, t2);
    suf.Add(i, {f[i], g[i]}), pre.Add(i, {f[i] - min[i], g[i]});
  }
  f[n] += F, g[n] += G;
  return g[n];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::partial_sum(a + 1, a + n + 1, b + 1);
  for (int i = 1; i <= n; i++) min[i] = std::min(min[i - 1], b[i]);
  std::copy(b, b + n + 1, c + 1);
  std::sort(c + 1, c + n + 2);
  nn = std::unique(c + 1, c + n + 2) - c - 1;
  for (int i = 0; i <= n; i++)
    d[i] = std::lower_bound(c + 1, c + nn + 1, b[i]) - c;
  long long l = -5000000000LL, r = 5000000000LL, best = r;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (Check(mid) >= k)
      best = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  Check(best);
  std::cout << f[n] + k * best;
  return 0;
}
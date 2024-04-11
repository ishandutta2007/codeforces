// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
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
int T, n, f[500001], g[500001];
long long a[500001], sum[500001], b[500005];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
  void Add(int x, const T v) {
    while (x <= n_) checkmax(t_[x], v), x += x & -x;
  }
  T Query(int x) {
    T s(0xc0c0c0c0);
    while (x) checkmax(s, t_[x]), x -= x & -x;
    return s;
  }
  void Clear() { std::memset(t_ + 1, 0xc0, sizeof(T) * n_); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[500005];
};
template <typename T = int>
class FenwickTree2 {
 public:
  FenwickTree2(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
  void Add(int x, const T v) {
    while (x) checkmax(t_[x], v), x -= x & -x;
  }
  T Query(int x) {
    T s(0xc0c0c0c0);
    while (x <= n_) checkmax(s, t_[x]), x += x & -x;
    return s;
  }
  void Clear() { std::memset(t_ + 1, 0xc0, sizeof(T) * n_); }
  ~FenwickTree2() {}

 private:
  int n_;
  T t_[500005];
};
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  sum[0] = 0, std::partial_sum(a + 1, a + n + 1, sum + 1);
  std::copy(sum, sum + n + 1, b + 1);
  std::sort(b + 1, b + n + 2);
  int nn = std::unique(b + 1, b + n + 2) - b - 1;
  for (int i = 0; i <= n; i++)
    sum[i] = std::lower_bound(b + 1, b + nn + 1, sum[i]) - b;
  FenwickTree bit(nn);
  FenwickTree2 bit2(nn);
  std::fill(g + 1, g + nn + 1, 0xc0c0c0c0);
  bit.Add(sum[0], 0), g[sum[0]] = 0, bit2.Add(sum[0], 0);
  std::fill(f + 1, f + n + 1, 0xc0c0c0c0);
  for (int i = 1; i <= n; i++) {
    int pre = bit.Query(sum[i] - 1);
    if (pre != 0xc0c0c0c0) checkmax(f[i], pre + i);
    if (g[sum[i]] != 0xc0c0c0c0) checkmax(f[i], g[sum[i]]);
    int nxt = bit2.Query(sum[i] + 1);
    if (nxt != 0xc0c0c0c0) checkmax(f[i], nxt - i);
    bit.Add(sum[i], f[i] - i);
    checkmax(g[sum[i]], f[i]);
    bit2.Add(sum[i], f[i] + i);
  }
  std::cout << f[n] << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
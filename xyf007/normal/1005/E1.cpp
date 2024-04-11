#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a[200001], b[200001];
class FenwickTree {
 public:
  FenwickTree() {}
  void set_n(int n) { n_ = n; }
  void Add(int x, int v = 1) {
    x += n + 1;
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  int Query(int x) {
    x += n + 1;
    int s = 0;
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::memset(t_, 0, sizeof(t_)); }
  ~FenwickTree() {}

 private:
  int n_, t_[400005];
} T;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i], b[i] = a[i] >= m ? 1 : -1;
  T.set_n(2 * n + 1);
  int s = 0;
  long long ans = 0LL;
  T.Add(0);
  for (int i = 1; i <= n; i++) s += b[i], ans += T.Query(s - 1), T.Add(s);
  T.Clear();
  for (int i = 1; i <= n; i++) b[i] = a[i] > m ? 1 : -1;
  s = 0;
  T.Add(0);
  for (int i = 1; i <= n; i++) s += b[i], ans -= T.Query(s - 1), T.Add(s);
  std::cout << ans;
  return 0;
}
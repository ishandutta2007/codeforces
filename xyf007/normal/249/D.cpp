#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a, b, c, d, f[100001];
std::pair<long long, long long> p[100001];
long long Y[100001];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
  void Add(int x, const T &v) {
    while (x <= n_) checkmax(t_[x], v), x += x & -x;
  }
  T Query(int x) {
    T s = 0;
    while (x) checkmax(s, t_[x]), x -= x & -x;
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
  std::string s1, s2;
  char slash;
  std::cin >> n >> s1 >> s2;
  std::stringstream ss;
  ss << s1, ss >> a >> slash >> b;
  std::stringstream().swap(ss);
  ss << s2, ss >> c >> slash >> d;
  for (int i = 1; i <= n; i++) {
    long long x, y;
    std::cin >> x >> y;
    long long xx = c * x - d * y, yy = b * y - a * x;
    if (xx > 0 && yy > 0) p[++m] = {xx, yy}, Y[m] = yy;
  }
  std::sort(Y + 1, Y + m + 1);
  int nn = std::unique(Y + 1, Y + m + 1) - Y - 1;
  for (int i = 1; i <= m; i++)
    p[i].second = std::lower_bound(Y + 1, Y + nn + 1, p[i].second) - Y;
  std::sort(p + 1, p + m + 1);
  FenwickTree bit(nn);
  for (int l = 1, r; l <= m; l = r + 1) {
    r = l;
    while (r < m && p[r + 1].first == p[l].first) r++;
    for (int i = l; i <= r; i++) f[i] = bit.Query(p[i].second - 1) + 1;
    for (int i = l; i <= r; i++) bit.Add(p[i].second, f[i]);
  }
  std::cout << *std::max_element(f + 1, f + m + 1);
  return 0;
}
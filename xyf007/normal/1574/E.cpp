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
constexpr int kMod = 998244353;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int fac[100001], inv[100001];
void Init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = Ksm(fac[n], kMod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
}
int C(int x, int y) {
  if (x < y || y < 0) return 0;
  return mul(fac[x], inv[x - y], inv[y]);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, q, pw[1000001], cnt[2];
std::map<std::pair<int, int>, int> mp;
class E {
 public:
  E() {}
  void Init(int n) { cnt_ = n; }
  int Calc() { return c0_ ? 0 : pw[cnt_]; }
  void Insert(int x, int y, int op) {
    int col = (x + op) & 1;
    a_[y][col]++;
    if (a_[y][col] == 1 && a_[y][col ^ 1]) c0_++;
    if (a_[y][col] == 1 && !a_[y][col ^ 1]) cnt_--;
  }
  void Erase(int x, int y, int op) {
    int col = (x + op) & 1;
    a_[y][col]--;
    if (!a_[y][col] && a_[y][col ^ 1]) c0_--;
    if (!a_[y][col] && !a_[y][col ^ 1]) cnt_++;
  }
  ~E() {}

 private:
  int cnt_, c0_, a_[1000001][2];
} r, c;
void Erase(int x, int y) {
  int col = mp[{x, y}];
  r.Erase(x, y, col), c.Erase(y, x, col);
  cnt[(x + y + col) & 1]--;
  mp.erase({x, y});
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  pw[0] = 1;
  for (int i = 1; i <= 1000000; i++) pw[i] = add(pw[i - 1], pw[i - 1]);
  std::cin >> n >> m >> q;
  r.Init(m), c.Init(n);
  while (q--) {
    int x, y, op;
    std::cin >> x >> y >> op;
    if (mp.count({x, y})) Erase(x, y);
    if (op != -1) {
      r.Insert(x, y, op), c.Insert(y, x, op);
      cnt[(x + y + op) & 1]++;
      mp[{x, y}] = op;
    }
    int ans = add(r.Calc(), c.Calc());
    if (!cnt[0]) Sub(ans, 1);
    if (!cnt[1]) Sub(ans, 1);
    std::cout << ans << '\n';
  }
  return 0;
}
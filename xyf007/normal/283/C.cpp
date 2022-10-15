#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7;
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
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
int n, m, t, a[301], fa[301], son[301], dp[100001];
bool vis[301];
class DisjointSet {
 public:
  DisjointSet() {}
  void set_n(int n) { n_ = n; }
  void Init() { std::iota(fa_ + 1, fa_ + n_ + 1, 1); }
  void set_fa(int x, int fa) { fa_[x] = fa; }
  int Find(int x) {
    if (x == fa_[x]) return x;
    return fa_[x] = Find(fa_[x]);
  }
  ~DisjointSet() {}

 private:
  int n_, fa_[301];
} T;
int main(int argc, char const *argv[]) {
  Read(n, m, t);
  T.set_n(n);
  T.Init();
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= m; i++) {
    int u, v, fu, fv;
    Read(u, v);
    son[u] = v;
    fa[v] = u;
    fu = T.Find(u);
    fv = T.Find(v);
    if (fu == fv) {
      std::printf("0");
      return 0;
    }
    T.set_fa(fu, fv);
  }
  for (int i = 1; i <= n; i++)
    if (!fa[i]) {
      int cnt = 0;
      for (int u = i; u; u = son[u]) cnt++;
      for (int u = i; u; u = son[u]) {
        t -= --cnt * a[u];
        if (t < 0) {
          std::printf("0");
          return 0;
        }
        a[u] += a[fa[u]];
      }
    }
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = a[i]; j <= t; j++) Add(dp[j], dp[j - a[i]]);
  std::printf("%d", dp[t]);
  return 0;
}
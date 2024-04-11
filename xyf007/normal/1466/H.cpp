#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 1e9 + 7;
template <typename T>
T add(T a, T b) {
  return a + b >= kMod ? a + b - kMod : a + b;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return a - b < 0 ? a - b + kMod : a - b;
}
template <typename T, typename... Args>
T sub(T a, T b, Args... args) {
  return sub(sub(a, b), args...);
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
  if ((a += b) >= kMod) a -= kMod;
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  if ((a -= b) < 0) a += kMod;
}
template <typename T, typename... Args>
void Sub(T &a, T b, Args... args) {
  Sub(a, add(b, args...));
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
int fac[41], inv[41];
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
int n, p[41], cnt[41], pw[41], f[1441], w[41][41];
bool vis[41];
int Encode(const std::vector<int> &a) {
  return std::inner_product(pw, pw + n + 1, a.begin(), 0);
}
std::vector<int> Decode(int S) {
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) a[i] = S % (cnt[i] + 1), S /= (cnt[i] + 1);
  return a;
}
std::vector<int> subs;
void Dfs(int now, int sta, const std::vector<int> &lim) {
  if (now == n + 1) {
    subs.emplace_back(sta);
    return;
  }
  for (int i = 0; i <= lim[now]; i++) Dfs(now + 1, sta + pw[now] * i, lim);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  Init(n);
  for (int i = 1; i <= n; i++) std::cin >> p[i];
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      int sz = 0;
      for (int j = i; !vis[j]; j = p[j]) sz++, vis[j] = true;
      cnt[sz]++;
    }
  for (int i = 1; i <= n; i++) {
    pw[i] = 1;
    for (int j = 1; j < i; j++) pw[i] *= cnt[j] + 1;
  }
  for (int i = 0; i < n; i++) w[0][i] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      Add(w[1][i], mul(C(i, j), fac[j], fac[n - j - 1]));
  for (int i = 2; i <= n; i++)
    for (int j = 0; j < n; j++) w[i][j] = mul(w[i - 1][j], w[1][j]);
  int full = Encode(std::vector<int>(cnt, cnt + n + 1));
  f[0] = 1;
  for (int S = 1; S <= full; S++) {
    std::vector<int> cnt = Decode(S);
    int ss = 0;
    for (int i = 1; i <= n; i++) ss += cnt[i] * i;
    subs.clear();
    Dfs(1, 0, cnt);
    for (const auto &T : subs)
      if (T) {
        std::vector<int> ct = Decode(T);
        int st = 0, coef = 1, sst = std::accumulate(ct.begin(), ct.end(), 0);
        for (int i = 1; i <= n; i++)
          st += ct[i] * i, Mul(coef, C(cnt[i], ct[i]));
        if (~sst & 1) coef = kMod - coef;
        Mul(coef, w[st][ss - st]);
        Add(f[S], mul(coef, f[S - T]));
      }
  }
  std::cout << f[full];
  return 0;
}
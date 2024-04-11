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
constexpr int kMod = 1e9 + 7;
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
int Ksm(int a, int b, int p) {
  int s = 1;
  while (b) {
    if (b & 1) s = s * static_cast<long long>(a) % p;
    a = a * static_cast<long long>(a) % p;
    b >>= 1;
  }
  return s;
}
int fac[1000001], inv[1000001], iv[1000001];
void Init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = Ksm(fac[n], kMod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
  iv[0] = iv[1] = 1;
  for (int i = 2; i <= n; i++) iv[i] = mul(kMod - kMod / i, iv[kMod % i]);
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
int k, n;
long long N;
std::vector<long long> all;
std::unordered_map<long long, int> mp, dp[7];
std::unordered_map<char, int> ccc{{'w', 1}, {'g', 2}, {'r', 3},
                                  {'o', 4}, {'b', 5}, {'y', 6}};
int Dp(long long x, int y) {
  if (dp[y].count(x)) return dp[y][x];
  if (x * 2 > N) {
    if (mp.count(x))
      return mp[x] == y;
    else
      return 1;
  }
  if (mp.count(x) && mp[x] != y) return 0;
  if (!std::binary_search(all.begin(), all.end(), x)) {
    int c = 0;
    long long tmp = x;
    while (tmp <= N) tmp *= 2, c++;
    return Ksm(4, (1LL << c) - 2);
  }
  int l = 0, r = 0;
  for (int i = 1; i <= 6; i++)
    if (i != y && i + y != 7) Add(l, Dp(x * 2, i)), Add(r, Dp(x * 2 + 1, i));
  return dp[y][x] = mul(l, r);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> k >> n, N = (1LL << k) - 1;
  for (int i = 1; i <= n; i++) {
    long long x;
    std::string s;
    std::cin >> x >> s;
    mp[x] = ccc[s[0]];
    while (x) all.emplace_back(x), x >>= 1;
  }
  std::sort(all.begin(), all.end());
  auto it = std::unique(all.begin(), all.end());
  all.erase(it, all.end());
  int ans = 0;
  for (int i = 1; i <= 6; i++) Add(ans, Dp(1LL, i));
  std::cout << ans;
  return 0;
}
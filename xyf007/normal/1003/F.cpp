#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
constexpr long long kBs = 41, kMod = 1019260817;
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
int n, pre[301];
long long pw[200001], hs[200001];
std::string a[301], s;
long long Calc(int l, int r) {
  return sub(hs[pre[r]], mul(hs[pre[l - 1]], pw[pre[r] - pre[l - 1]]));
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i], s += a[i] + '#', pre[i] = pre[i - 1] + a[i].size() + 1;
  pw[0] = 1;
  for (std::size_t i = 1; i <= s.size(); i++) pw[i] = mul(pw[i - 1], kBs);
  for (std::size_t i = 1; i <= s.size(); i++)
    hs[i] = add(mul(hs[i - 1], kBs), static_cast<long long>(s[i - 1]));
  std::size_t ans = s.size() - 1;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      int l = j - i + 1, d = pre[j] - pre[i - 1] - l - 1, h = Calc(i, j), c = 1;
      for (int k = j + 1; k + l - 1 <= n; k++)
        if (Calc(k, k + l - 1) == h) {
          k = k + l - 1;
          c++;
        }
      if (c > 1) checkmin(ans, s.size() - 1 - c * d);
    }
  std::cout << ans;
  return 0;
}
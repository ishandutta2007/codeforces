#include <cctype>
#include <iostream>
constexpr int kB = 1 << 20;
char wbuf[kB + 1], *po = wbuf;
void Putchar(const char &c) {
  if (po - wbuf == kB) std::cout.write(wbuf, kB), po = wbuf;
  *po++ = c;
}
template <typename T>
void Write(const T &x) {
  if (x < 0) {
    Putchar('-'), Write(-x);
    return;
  }
  if (x > 9) Write(x / 10);
  Putchar(x % 10 + '0');
}
void Write(const char c) { Putchar(c); }
template <typename T, typename... Args>
void Write(const T &x, const Args &...args) {
  Write(x), Write(args...);
}
constexpr int kBase = 100003, kMod = 1019260817;
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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, ans[500005];
long long pw[1000005], hs[1000005];
char s[1000005];
int Calc(int l, int r) { return sub(hs[r], mul(hs[l - 1], pw[r - l + 1])); }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> (s + 1);
  pw[0] = 1LL;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * kBase % kMod;
  for (int i = 1; i <= n; i++) hs[i] = (hs[i - 1] * kBase + s[i]) % kMod;
  int k = (n + 1) >> 1, l = k, r = n - k + 1;
  if (n & 1)
    ans[k] = -1;
  else
    ans[k] = s[k] == s[k + 1] ? 1 : -1;
  l--, r++;
  for (int i = k - 1; i >= 1; i--, l--, r++) {
    ans[i] = ans[i + 1] + 2;
    while (ans[i] > 0 && Calc(l, l + ans[i] - 1) != Calc(r - ans[i] + 1, r))
      ans[i] -= 2;
  }
  for (int i = 1; i <= k; i++) Write(ans[i], ' ');
  std::cout.write(wbuf, po - wbuf);
  return 0;
}
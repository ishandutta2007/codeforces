#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kBase = 41, kMod = 1e9 + 7;
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
std::size_t n, m, k;
char a[1000001], b[201];
bool f[2001][201];
int ans[2001], c[2001], hs[2001];
int main(int argc, char const *argv[]) {
  std::cin.getline(a, 1000001).getline(b, 201);
  Read(k);
  n = std::strlen(a);
  m = std::strlen(b);
  std::size_t t = n / k;
  for (std::size_t i = 0; i < k; i++)
    for (std::size_t j = i; j < n; j += k)
      hs[i] = add(mul(hs[i], kBase), static_cast<int>(a[j]));
  ans[0] = 2;
  for (std::size_t l = 1; l <= k && l <= m; l++) {
    if (t * l + std::min(l, n % k) < m ||
        t * l + (l + n % k > k ? l + n % k - k : 0) > m)
      continue;
    std::memset(f, false, sizeof(f));
    for (std::size_t i = 0; i < k; i++)
      for (std::size_t j = 0; j <= i && j < m; j++) {
        int h = 0;
        for (std::size_t p = j; p < m; p += l)
          h = add(mul(h, kBase), static_cast<int>(b[p]));
        f[i][j] = hs[i] == h;
      }
    std::memset(c, 0, sizeof(c));
    int cnt = m - t * l, d = n % k, now = cnt - 1;
    for (int i = d - 1; i >= 0; i--)
      if (now >= 0 && f[i][now]) {
        c[i] = 1;
        now--;
      }
    if (now >= 0) continue;
    now = l - 1;
    for (int i = k - 1; i >= d; i--)
      if (now >= cnt && f[i][now]) {
        c[i] = 1;
        now--;
      }
    if (now >= cnt) continue;
    for (std::size_t i = 0; i < k; i++) {
      if (c[i] > ans[i]) break;
      if (c[i] < ans[i]) {
        std::memcpy(ans, c, 4 * k);
        break;
      }
    }
  }
  if (ans[0] == 2)
    std::printf("0");
  else
    for (std::size_t i = 0; i < k; i++) std::printf("%d", ans[i]);
  return 0;
}
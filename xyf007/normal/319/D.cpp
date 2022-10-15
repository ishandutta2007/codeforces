#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
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
std::size_t n, vis[50001];
char s[50001];
int pw[50001], hs[50001], max;
int GetHash(std::size_t l, std::size_t r) {
  return sub(hs[r], mul(hs[l - 1], pw[r - l + 1]));
}
std::size_t GetLcp(std::size_t x, std::size_t y) {
  std::size_t l = 1, r = max, best = 0;
  while (l <= r) {
    std::size_t mid = (l + r) >> 1;
    if (GetHash(x - mid + 1, x) == GetHash(y - mid + 1, y)) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return best;
}
std::size_t GetLcs(std::size_t x, std::size_t y) {
  std::size_t l = 1, r = n - y + 1, best = 0;
  while (l <= r) {
    std::size_t mid = (l + r) >> 1;
    if (GetHash(x, x + mid - 1) == GetHash(y, y + mid - 1)) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return best;
}
int main(int argc, char const *argv[]) {
  std::scanf("%s", s + 1);
  n = std::strlen(s + 1);
  pw[0] = 1;
  for (std::size_t i = 1; i <= n; i++) {
    pw[i] = mul(pw[i - 1], kBase);
    hs[i] = add(mul(hs[i - 1], kBase), static_cast<int>(s[i]));
  }
  for (std::size_t len = 1; len <= n; len++) {
    bool f = false;
    std::size_t i = len, j = 2 * len;
    max = len;
    while (j <= n) {
      std::size_t lcp = GetLcp(i, j), lcs = GetLcs(i, j);
      if (lcp + lcs > len) {
        for (std::size_t k = i - lcp + 1; k <= i - lcp + len; k++) vis[k] = len;
        max = lcp;
        f = true;
      } else {
        max = len;
      }
      i += len;
      j += len;
    }
    if (f) {
      std::size_t cnt = 0;
      for (std::size_t i = 1; i <= n; i++)
        if (vis[i] != len) s[++cnt] = s[i];
      n = cnt;
      for (std::size_t i = 1; i <= n; i++)
        hs[i] = add(mul(hs[i - 1], kBase), static_cast<int>(s[i]));
    }
  }
  for (std::size_t i = 1; i <= n; i++) std::printf("%c", s[i]);
  return 0;
}
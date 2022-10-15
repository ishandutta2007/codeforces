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
int n, m, k, pw[1000001], sum[1000001];
bool vis[1000001];
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = add(pw[i - 1], pw[i - 1]);
  int min = 0, max = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    Read(u, v);
    if (v != u + 1 && v != u + k + 1) {
      std::printf("0");
      return 0;
    }
    if (v == u + k + 1) {
      if (!min) min = u;
      vis[max = u] = true;
    }
  }
  int ans = 0;
  if (!min) {
    for (int i = 1; i <= n - k - 1; i++) {
      int u = i + k + k + 1 > n ? n - k - 1 : i + k;
      Add(ans, pw[u - i]);
    }
    std::printf("%d", add(ans, 1));
    return 0;
  }
  if (min + k < max) {
    std::printf("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + vis[i];
  for (int i = 1; i <= n - k - 1; i++) {
    if (i + k < max || min + k < i || vis[i]) continue;
    int mn = std::min(min, i), u = mn + k + k + 1 > n ? n - k - 1 : mn + k;
    Add(ans, pw[u - i - sum[u] + sum[i - 1]]);
  }
  std::printf("%d", add(ans, 1));
  return 0;
}
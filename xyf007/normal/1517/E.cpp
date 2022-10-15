#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 998244353;
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
void Read(T &x, Args &... args) {
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
int n, t;
long long a[200001], sum[200001], sum2[200001], maxc;
int Solve(int st, int r, long long s) {
  int l = 1, best = 0;
  while (l <= r) {
    int mid = (l + r) >> 1, pos = st + 2 * mid;
    if (sum2[pos] <= s) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return best + 1;
}
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n);
    for (int i = 1; i <= n; i++) Read(a[i]);
    std::partial_sum(a + 1, a + n + 1, sum + 1);
    sum2[1] = a[1];
    for (int i = 2; i <= n; i++) sum2[i] = sum2[i - 2] + a[i];
    maxc = (sum[n] - 1) >> 1;
    // P CCCC PCPC PPPP C
    int ans = 0;
    for (int i = 2; i <= n - 2; i++) {
      long long s = maxc - sum[i] + a[1] - a[n];
      if (s >= 0) Add(ans, Solve(i, (n - 2 - i) >> 1, s + sum2[i]));
    }
    // PPPPCCCC
    for (int i = 1; i < n; i++) ans += sum[n] - sum[i] <= maxc;
    // CCCC PCPC PPPP C
    for (int i = 1; i <= n - 2; i++) {
      long long s = maxc - sum[i] - a[n];
      if (s >= 0) Add(ans, Solve(i, (n - 2 - i) >> 1, s + sum2[i]));
    }
    // P CCCC PCPC PPPP
    for (int i = 2; i <= n - 1; i++) {
      long long s = maxc - sum[i] + a[1];
      if (s >= 0) Add(ans, Solve(i, (n - 1 - i) >> 1, s + sum2[i]));
    }
    // PPPP
    ans++;
    // CCCC PCPC PPPP
    for (int i = 1; i <= n - 1; i++) {
      long long s = maxc - sum[i];
      if (s >= 0) Add(ans, Solve(i, (n - 1 - i) >> 1, s + sum2[i]));
    }
    std::printf("%d\n", ans);
  }
  return 0;
}
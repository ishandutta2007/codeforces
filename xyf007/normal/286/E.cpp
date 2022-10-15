#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kMod = 998244353, kG = 3, kN = 2097152;
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
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int n, m, a[1000001], f[4000001], rev[4000001];
bool vis[1000001];
void Ntt(int *a, int n, int op) {
  for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | (i & 1) << 20;
  for (int i = 0; i < n; i++)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int len = 1; len < n; len <<= 1) {
    int wn = Ksm(kG, (kMod - 1) / (len << 1));
    if (op == -1) wn = Ksm(wn, kMod - 2);
    for (int i = 0; i < n; i += len << 1) {
      int w = 1, a1, a2;
      for (int j = 0; j < len; j++) {
        a1 = a[i + j];
        a2 = mul(a[i + j + len], w);
        a[i + j] = add(a1, a2);
        a[i + j + len] = sub(a1, a2);
        Mul(w, wn);
      }
    }
  }
  if (op == -1) {
    int inv = Ksm(n, kMod - 2);
    for (int i = 0; i < n; i++) Mul(a[i], inv);
  }
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
    f[a[i]] = 1;
    vis[a[i]] = true;
  }
  Ntt(f, kN, 1);
  for (int i = 0; i < kN; i++) Mul(f[i], f[i]);
  Ntt(f, kN, -1);
  for (int i = 1; i <= m; i++)
    if (f[i] && !vis[i]) {
      std::printf("NO");
      return 0;
    }
  std::printf("YES\n%ld\n",
              std::count_if(a + 1, a + n + 1,
                            [](const int &lhs) -> bool { return !f[lhs]; }));
  for (int i = 1; i <= n; i++)
    if (!f[a[i]]) std::printf("%d ", a[i]);
  return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
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
int n, p, a[100001], b[100001], c[200001];
std::vector<int> v[200001];
template <typename T>
T add(T a, T b) {
  return (a + b) % p;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + p - b) % p;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % p;
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
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= n; i++) Read(b[i]);
  Read(p);
  std::memcpy(c + 1, a + 1, 4 * n);
  std::memcpy(c + n + 1, b + 1, 4 * n);
  std::sort(c + 1, c + 2 * n + 1);
  int nn = std::unique(c + 1, c + 2 * n + 1) - c - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = std::lower_bound(c + 1, c + nn + 1, a[i]) - c;
    v[a[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; i++) {
    b[i] = std::lower_bound(c + 1, c + nn + 1, b[i]) - c;
    v[b[i]].emplace_back(i);
  }
  std::size_t ans = 1;
  std::unordered_set<int> s;
  for (int i = 1; i <= nn; i++) {
    std::unordered_set<int>().swap(s);
    for (auto &&j : v[i]) s.emplace(j);
    std::size_t tot = v[i].size() - s.size(), s = 1;
    for (std::size_t j = 1; j <= v[i].size(); j++) {
      std::size_t tmp = j;
      while (tot && !(tmp % 2)) {
        tot--;
        tmp >>= 1;
      }
      Mul(s, tmp);
    }
    Mul(ans, s);
  }
  std::cout << ans;
  return 0;
}
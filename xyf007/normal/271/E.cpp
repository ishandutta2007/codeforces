#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <unordered_set>
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
int n, m, a[100001];
std::unordered_set<int> s;
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) Read(a[i]);
  int gcd = a[1] - 1;
  for (int i = 2; i <= n; i++) gcd = std::__gcd(gcd, a[i] - 1);
  long long ans = 0LL;
  for (int i = 1; i * i <= gcd; i++) {
    if (gcd % i) continue;
    int d = i;
    while (!s.count(d) && d < m) {
      ans += m - d;
      s.emplace(d);
      d <<= 1;
    }
    if (i * i == gcd) break;
    d = gcd / i;
    while (!s.count(d) && d < m) {
      ans += m - d;
      s.emplace(d);
      d <<= 1;
    }
  }
  std::cout << ans;
  return 0;
}
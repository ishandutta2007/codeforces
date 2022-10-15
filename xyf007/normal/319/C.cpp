#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <numeric>
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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
int n;
long long a[100001], b[100001], dp[100001];
std::deque<int> q;
double Slope(int i, int j) {
  return (dp[j] - dp[i]) / static_cast<double>(b[j] - b[i]);
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= n; i++) Read(b[i]);
  std::memset(dp, 0x3f, sizeof(dp));
  dp[1] = 0;
  q.emplace_back(1);
  for (int i = 2; i <= n; i++) {
    while (q.size() > 1 && Slope(q[0], q[1]) > -a[i]) q.pop_front();
    dp[i] = dp[q.front()] + b[q.front()] * a[i];
    while (q.size() > 1 &&
           Slope(q.back(), i) >= Slope(q[q.size() - 2], q.back()))
      q.pop_back();
    q.emplace_back(i);
  }
  std::printf("%lld", dp[n]);
  return 0;
}
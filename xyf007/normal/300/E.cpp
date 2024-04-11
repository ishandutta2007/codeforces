#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, p[700001], tot, min[10000001], suf[10000002];
bool not_prime[10000001];
long long cnt[10000001];
bool Check(long long x) {
  for (int i = 1; i <= tot; i++) {
    long long tmp = x, s = 0LL;
    while (tmp) s += tmp /= p[i];
    if (s < cnt[p[i]]) return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  not_prime[1] = true;
  for (int i = 2; i <= 10000000; i++) {
    if (!not_prime[i]) p[++tot] = min[i] = i;
    for (int j = 1; j <= tot && i * p[j] <= 10000000; j++) {
      not_prime[i * p[j]] = true;
      min[i * p[j]] = p[j];
      if (!(i % p[j])) break;
    }
  }
  Read(n);
  for (int i = 1; i <= n; i++) {
    int x;
    Read(x);
    suf[x]++;
  }
  for (int i = 10000000; i >= 1; i--) suf[i] += suf[i + 1];
  for (int i = 1; i <= tot; i++)
    for (long long j = p[i]; j <= 10000000; j *= p[i])
      for (int k = j; k <= 10000000; k += j) cnt[p[i]] += suf[k];
  long long l = 1, r = 1e18, best = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::printf("%lld", best);
  return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
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
int n, tot, ch[5000001][2], cnt[5000001];
long long a[100001];
void Insert(long long x) {
  int now = 0;
  for (int i = 39; i >= 0; i--) {
    int d = (x >> i) & 1;
    if (!ch[now][d]) ch[now][d] = ++tot;
    cnt[now = ch[now][d]]++;
  }
}
long long Query(long long x) {
  int now = 0;
  long long ans = 0LL;
  for (int i = 39; i >= 0; i--) {
    int d = (x >> i) & 1;
    if (cnt[ch[now][d ^ 1]]) {
      now = ch[now][d ^ 1];
      ans += 1LL << i;
    } else {
      now = ch[now][d];
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  Read(n);
  long long s = 0LL, ans = 0LL;
  Insert(0LL);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
    s ^= a[i];
    Insert(s);
  }
  s = 0LL;
  checkmax(ans, Query(0LL));
  for (int i = n; i >= 1; i--) {
    s ^= a[i];
    checkmax(ans, Query(s));
  }
  std::cout << ans;
  return 0;
}
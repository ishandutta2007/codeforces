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
int n, ch[20000001][2], tot, cnt[20000001], a[1000001];
void Insert(int x) {
  int now = 0;
  for (int i = 19; i >= 0; i--) {
    int id = (x >> i) & 1;
    if (!ch[now][id]) ch[now][id] = ++tot;
    cnt[now = ch[now][id]]++;
  }
}
int Query(int x) {
  int now = 0, ans = 0;
  for (int i = 19; i >= 0; i--) {
    int id = (x >> i) & 1;
    if (cnt[ch[now][id ^ 1]]) {
      ans += 1 << i;
      cnt[now = ch[now][id ^ 1]]--;
    } else {
      cnt[now = ch[now][id]]--;
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 0; i <= n; i++) Insert(i);
  long long ans = 0LL;
  for (int i = 0; i <= n; i++) ans += a[i] = Query(i);
  std::printf("%lld\n", ans);
  for (int i = 0; i <= n; i++) std::printf("%d ", a[i] ^ i);
  return 0;
}
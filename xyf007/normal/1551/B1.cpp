#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
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
int t, n, cnt[26];
char s[101];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    std::scanf("%s", s + 1);
    n = std::strlen(s + 1);
    for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
    int ans = 0, c1 = 0;
    for (int i = 0; i < 26; i++)
      if (cnt[i] > 1)
        ans++;
      else if (cnt[i] == 1)
        c1++;
    std::printf("%d\n", ans + c1 / 2);
    std::memset(cnt, 0, sizeof(cnt));
  }
  return 0;
}
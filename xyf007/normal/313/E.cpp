#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
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
int n, m, ans[100001];
std::multiset<int> sa, sb;
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) {
    int x;
    Read(x);
    sa.emplace(x %= m);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    Read(x);
    sb.emplace(x %= m);
  }
  for (int i = 1; i <= n; i++) {
    auto it1 = --sa.end(), it2 = --sb.end(), it3 = sb.lower_bound(m - *it1),
         it4 = sa.lower_bound(m - *it2);
    int ma = *it1, mb = *it2, max = (ma + mb) % m, op = 1;
    if (it3 != sb.begin())
      if (*--it3 + ma > max) {
        max = *it3 + ma;
        op = 2;
      }
    if (it4 != sa.begin())
      if (*--it4 + mb > max) {
        max = *it4 + mb;
        op = 3;
      }
    ans[i] = max;
    if (op == 1) {
      sa.erase(it1);
      sb.erase(it2);
    } else if (op == 2) {
      sa.erase(it1);
      sb.erase(it3);
    } else {
      sa.erase(it4);
      sb.erase(it2);
    }
  }
  std::sort(ans + 1, ans + n + 1, std::greater<int>());
  for (int i = 1; i <= n; i++) std::printf("%d ", ans[i]);
  return 0;
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
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
int n, m, q, B, pos[100001], cnt, c[351][100001];
long long a[100001], tag[351], sum[351];
std::vector<int> v[100001];
std::bitset<100001> b[351];
int main(int argc, char const *argv[]) {
  Read(n, m, q);
  B = std::sqrt(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= m; i++) {
    int k, x;
    Read(k);
    for (int j = 1; j <= k; j++) {
      Read(x);
      v[i].emplace_back(x);
    }
    if (k >= B) {
      pos[i] = ++cnt;
      for (auto &&j : v[i]) {
        b[cnt].set(j);
        sum[cnt] += a[j];
      }
    }
  }
  for (int i = 1; i <= cnt; i++)
    for (int j = 1; j <= m; j++)
      for (auto &&k : v[j]) c[i][j] += b[i].test(k);
  while (q--) {
    char op[10];
    int k, x;
    std::scanf("%s", op);
    Read(k);
    if (op[0] == '?') {
      long long ans = 0LL;
      if (pos[k])
        ans = sum[pos[k]];
      else
        for (auto &&i : v[k]) ans += a[i];
      for (int i = 1; i <= cnt; i++) ans += tag[i] * c[i][k];
      std::printf("%lld\n", ans);
    } else {
      Read(x);
      if (pos[k]) {
        tag[pos[k]] += x;
      } else {
        for (auto &&i : v[k]) a[i] += x;
        for (int i = 1; i <= cnt; i++) sum[i] += x * c[i][k];
      }
    }
  }
  return 0;
}
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
int n, m, p, d[100001];
long long t[100001], sum[100001], dp[101][100001];
std::deque<int> q[100001];
double Slope(int i, int j1, int j2) {
  return (dp[i][j1] + sum[j1] - dp[i][j2] - sum[j2]) /
         static_cast<double>(j1 - j2);
}
int main(int argc, char const *argv[]) {
  Read(n, m, p);
  for (int i = 2; i <= n; i++) Read(d[i]);
  std::partial_sum(d + 1, d + n + 1, d + 1);
  for (int i = 1; i <= m; i++) {
    int p, x;
    Read(p, x);
    t[i] = x - d[p];
  }
  std::sort(t + 1, t + m + 1);
  std::partial_sum(t + 1, t + m + 1, sum + 1);
  q[0].emplace_back(0);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= p && j <= i; j++) {
      while (q[j - 1].size() > 1 &&
             Slope(j - 1, q[j - 1][0], q[j - 1][1]) <= t[i])
        q[j - 1].pop_front();
      int k = q[j - 1].front();
      dp[j][i] = dp[j - 1][k] + t[i] * (i - k) - sum[i] + sum[k];
      while (q[j].size() > 1 &&
             Slope(j, q[j].back(), i) <
                 Slope(j, q[j][q[j].size() - 2], q[j].back()))
        q[j].pop_back();
      q[j].emplace_back(i);
    }
  std::printf("%lld", dp[p][m]);
  return 0;
}
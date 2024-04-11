#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <cstring>
#include <iostream>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, q, f[100001][2];
char l[100005], r[100005], u[100005], d[100005];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q >> (l + 1) >> (r + 1) >> (u + 1) >> (d + 1);
  int ans = 0x3f3f3f3f;
  std::memset(f, 0x3f, sizeof(f));
  f[1][0] = std::count(l + 1, l + n + 1, 'B') + (u[1] == 'B') + (d[1] == 'B');
  f[1][1] = std::count(l + 1, l + n + 1, 'R') + (u[1] == 'R') + (d[1] == 'R');
  for (int i = 2; i <= m; i++) {
    f[i][0] =
        std::min(f[i - 1][0], f[i - 1][1] + n) + (u[i] == 'B') + (d[i] == 'B');
    f[i][1] =
        std::min(f[i - 1][0] + n, f[i - 1][1]) + (u[i] == 'R') + (d[i] == 'R');
  }
  checkmin(ans, f[m][0] + std::count(r + 1, r + n + 1, 'B'));
  checkmin(ans, f[m][1] + std::count(r + 1, r + n + 1, 'R'));
  std::memset(f, 0x3f, sizeof(f));
  f[1][0] = std::count(u + 1, u + m + 1, 'B') + (l[1] == 'B') + (r[1] == 'B');
  f[1][1] = std::count(u + 1, u + m + 1, 'R') + (l[1] == 'R') + (r[1] == 'R');
  for (int i = 2; i <= n; i++) {
    f[i][0] =
        std::min(f[i - 1][0], f[i - 1][1] + m) + (l[i] == 'B') + (r[i] == 'B');
    f[i][1] =
        std::min(f[i - 1][0] + m, f[i - 1][1]) + (l[i] == 'R') + (r[i] == 'R');
  }
  checkmin(ans, f[n][0] + std::count(d + 1, d + m + 1, 'B'));
  checkmin(ans, f[n][1] + std::count(d + 1, d + m + 1, 'R'));
  std::cout << ans;
  return 0;
}
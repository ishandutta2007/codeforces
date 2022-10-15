#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <algorithm>
#include <iostream>
#include <numeric>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, q, a[20005], st[16][20005], lg[20005], f[16][32][20005];
inline int Max(int x, int y) { return x + a[x] > y + a[y] ? x : y; }
inline void Checkmax(int &x, int y) { x = Max(x, y); }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++)
    if (a[i] + i > n + 1) a[i] = n - i + 1;
  a[n + 1] = 1;
  for (int i = 2; i <= n + 1; i++) lg[i] = lg[i >> 1] + 1;
  std::iota(st[0] + 1, st[0] + n + 2, 1);
  for (int i = 1; i <= lg[n + 1]; i++)
    for (int j = 1; j + (1 << i) - 1 <= n + 1; j++)
      st[i][j] = Max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  auto query = [](int l, int r) {
    int len = lg[r - l + 1];
    return Max(st[len][l], st[len][r - (1 << len) + 1]);
  };
  for (int i = 0; i <= lg[n]; i++)
    for (int j = 0; j <= 30; j++) f[i][j][n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    f[0][0][i] = query(i + 1, i + a[i]);
    for (int j = 1; j <= 30; j++) f[0][j][i] = i + a[i] + j;
  }
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 0; j <= 30; j++)
      for (int k = 0; k <= 30 - j; k++)
        for (int l = 1; l <= n; l++)
          Checkmax(f[i][j + k][l], f[i - 1][j][f[i - 1][k][l]]);
  while (q--) {
    int l, r, k;
    std::cin >> l >> r >> k;
    if (l == r) {
      std::cout << "0\n";
      continue;
    }
    if (l + a[l] + k >= r) {
      std::cout << "1\n";
      continue;
    }
    int ans = 2, R[32];
    std::fill(R, R + k + 1, l);
    for (int i = lg[r - l + 1]; i >= 0; i--) {
      bool ok = false;
      for (int j = 0; j <= k && !ok; j++)
        for (int l = 0; l <= k - j; l++) {
          int p = f[i][j][R[l]];
          if (p + a[p] + k - j - l >= r) {
            ok = true;
            break;
          }
        }
      if (ok) continue;
      ans += 1 << i;
      for (int j = k; j >= 0; j--)
        for (int l = k - j; l >= 0; l--) Checkmax(R[j + l], f[i][l][R[j]]);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
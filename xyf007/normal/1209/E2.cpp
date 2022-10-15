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
int n, m, a[2001][13], mx[2001], ord[2001], f[13][4097], w[13][4097];
void Solve() {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= m; j++) std::cin >> a[j][i];
  for (int i = 1; i <= m; i++) mx[i] = *std::max_element(a[i], a[i] + n);
  std::iota(ord + 1, ord + m + 1, 1);
  std::sort(ord + 1, ord + m + 1,
            [](const int lhs, const int rhs) { return mx[lhs] > mx[rhs]; });
  int N = std::min(n, m);
  for (int i = 1; i <= N; i++) std::fill(w[i], w[i] + (1 << n), 0);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < n; j++) {
      for (int S = 0; S < (1 << n); S++) {
        int sum = 0;
        for (int k = 0; k < n; k++)
          if (S >> k & 1) sum += a[ord[i]][k];
        checkmax(w[i][S], sum);
      }
      std::rotate(a[ord[i]], a[ord[i]] + 1, a[ord[i]] + n);
    }
  }
  std::fill(f[0] + 1, f[0] + (1 << n), 0xc0c0c0c0);
  for (int i = 1; i <= N; i++)
    for (int S = 0; S < (1 << n); S++) {
      f[i][S] = f[i - 1][S];
      for (int T = S; T; T = (T - 1) & S)
        checkmax(f[i][S], f[i - 1][S ^ T] + w[i][T]);
    }
  std::cout << f[N][(1 << n) - 1] << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
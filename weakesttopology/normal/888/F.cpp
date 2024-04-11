#include <bits/stdc++.h>

constexpr int mod = 1e9 + 7, Nmax = 500;
int a[Nmax][Nmax];
bool vis_connected[Nmax][Nmax], vis_unconnected[Nmax][Nmax];
int64_t dp_connected[Nmax][Nmax], dp_unconnected[Nmax][Nmax];

int64_t solve_unconnected(int l, int r);

int64_t solve_connected(int l, int r) {
    int64_t& res = dp_connected[l][r];
    if (vis_connected[l][r]) {
      return res;
    }
    vis_connected[l][r] = true;
    for (int i = l + 1; i < r; ++i) {
      if (!a[l][i]) continue;
      res += solve_connected(l, i) * solve_connected(i, r);
      res %= mod;
    }
    res += solve_unconnected(l + 1, r);
    res %= mod;
    return res;
}

int64_t solve_unconnected(int l, int r) {
    int64_t& res = dp_unconnected[l][r];
    if (vis_unconnected[l][r]) {
      return res;
    }
    vis_unconnected[l][r] = true;
    for (int i = l + 1; i <= r; ++i) {
      if (!a[i][l]) continue;
      res += solve_connected(l, i) * solve_unconnected(i, r);
      res %= mod;
    }
    return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    vis_connected[i][i] = true;
    dp_connected[i][i] = 1;
    vis_unconnected[i][i] = true;
    dp_unconnected[i][i] = 1;
  }
  std::cout << solve_unconnected(0, N - 1) << '\n';
  exit(0);
}
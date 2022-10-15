#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
constexpr long long kInf = 0x3f3f3f3f3f3f3f3fLL;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a[1000001];
long long p, sum[4000001];
std::vector<long long> c[4000001];
void Pushup(int l, int r, int x) {
  sum[x] = sum[x + x] + sum[x + x + 1];
  int mid = (l + r) >> 1;
  for (int xx = 0, yy = 0; xx <= mid - l + 1; xx++) {
    if (yy == r - mid + 1) yy--;
    while (yy <= r - mid) {
      if (c[x + x][xx + 1] - 1 + sum[x + x] - xx * p >= c[x + x + 1][yy]) {
        checkmin(
            c[x][xx + yy],
            std::max(c[x + x][xx], c[x + x + 1][yy] - sum[x + x] + xx * p));
      } else {
        yy--;
        break;
      }
      yy++;
    }
  }
}
void Build(int l, int r, int x) {
  c[x].resize(r - l + 3);
  c[x][0] = -kInf;
  for (int i = 1; i <= r - l + 2; i++) c[x][i] = kInf;
  if (l == r) {
    sum[x] = a[l], c[x][1] = p - a[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(l, r, x);
}
long long Query(int L, int R, int l, int r, long long in, int x) {
  if (L <= l && r <= R) {
    std::ptrdiff_t po =
        std::prev(std::upper_bound(c[x].begin(), c[x].end(), in)) -
        c[x].begin();
    return in + sum[x] - po * p;
  }
  int mid = (l + r) >> 1;
  if (R <= mid) return Query(L, R, l, mid, in, x + x);
  if (L > mid) return Query(L, R, mid + 1, r, in, x + x + 1);
  return Query(L, R, mid + 1, r, Query(L, R, l, mid, in, x + x), x + x + 1);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  Build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << Query(l, r, 1, n, 0LL, 1) << '\n';
  }
  return 0;
}
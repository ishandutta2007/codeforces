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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a[100001], max[400001];
long long sum[400001];
void Pushup(int x) {
  max[x] = std::max(max[x + x], max[x + x + 1]);
  sum[x] = sum[x + x] + sum[x + x + 1];
}
void Build(int l, int r, int x) {
  if (l == r) {
    max[x] = sum[x] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int l, int r, int p, int v, int x) {
  if (l == r) {
    max[x] = sum[x] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify(l, mid, p, v, x + x);
  else
    Modify(mid + 1, r, p, v, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int p, int x) {
  if (max[x] < p) return;
  if (l == r) {
    sum[x] = max[x] %= p;
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, p, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, p, x + x + 1);
  Pushup(x);
}
long long Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return sum[x];
  int mid = (l + r) >> 1;
  long long ans = 0LL;
  if (L <= mid) ans += Query(L, R, l, mid, x + x);
  if (R > mid) ans += Query(L, R, mid + 1, r, x + x + 1);
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  Build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int op, l, r, k, x;
    std::cin >> op;
    if (op == 1) {
      std::cin >> l >> r;
      std::cout << Query(l, r, 1, n, 1) << '\n';
    } else if (op == 2) {
      std::cin >> l >> r >> x;
      Modify(l, r, 1, n, x, 1);
    } else {
      std::cin >> k >> x;
      Modify(1, n, k, x, 1);
    }
  }
  return 0;
}
#include <algorithm>
#include <cstring>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a[100001], b[300001], l[100001], r[100001], tag[1200001], s0[1200001],
    s1[1200001];
bool vis[300001];
void Pushup(int x) {
  s0[x] = s0[x + x] + s0[x + x + 1], s1[x] = s1[x + x] + s1[x + x + 1];
}
void Reverse(int x) { std::swap(s0[x], s1[x]), tag[x] ^= 1; }
void Pushdown(int x) {
  if (tag[x]) {
    Reverse(x + x), Reverse(x + x + 1);
    tag[x] ^= 1;
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    s0[x] = vis[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return Reverse(x);
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, x + x + 1);
  Pushup(x);
}
int Query0(int L, int R, int l, int r, int x) {
  if (L > R) return 0;
  if (L <= l && r <= R) return s0[x];
  Pushdown(x);
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid) ans += Query0(L, R, l, mid, x + x);
  if (R > mid) ans += Query0(L, R, mid + 1, r, x + x + 1);
  return ans;
}
int Query1(int L, int R, int l, int r, int x) {
  if (L > R) return 0;
  if (L <= l && r <= R) return s1[x];
  Pushdown(x);
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid) ans += Query1(L, R, l, mid, x + x);
  if (R > mid) ans += Query1(L, R, mid + 1, r, x + x + 1);
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= m; i++) std::cin >> l[i] >> r[i];
  std::memcpy(b + 1, a + 1, 4 * n);
  std::memcpy(b + n + 1, l + 1, 4 * m);
  std::memcpy(b + n + m + 1, r + 1, 4 * m);
  std::sort(b + 1, b + n + 2 * m + 1);
  int nn = std::unique(b + 1, b + n + 2 * m + 1) - b - 1;
  for (int i = 1; i <= n; i++)
    a[i] = std::lower_bound(b + 1, b + nn + 1, a[i]) - b;
  for (int i = 1; i <= m; i++)
    l[i] = std::lower_bound(b + 1, b + nn + 1, l[i]) - b;
  for (int i = 1; i <= m; i++)
    r[i] = std::lower_bound(b + 1, b + nn + 1, r[i]) - b;
  std::vector<std::vector<int>> ad(nn + 1), de(nn + 1);
  for (int i = 1; i <= n; i++) vis[a[i]] = true;
  for (int i = 1; i <= m; i++) ad[l[i]].push_back(i);
  for (int i = 1; i <= m; i++) de[r[i]].push_back(i);
  Build(1, nn, 1);
  long long ans = static_cast<long long>(n) * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= nn; i++) {
    for (const auto &j : ad[i]) Modify(l[j], r[j], 1, nn, 1);
    if (vis[i]) {
      long long win = Query0(1, i - 1, 1, nn, 1) + Query1(i + 1, nn, 1, nn, 1);
      ans -= win * (win - 1) >> 1;
    }
    for (const auto &j : de[i]) Modify(l[j], r[j], 1, nn, 1);
  }
  std::cout << ans;
  return 0;
}
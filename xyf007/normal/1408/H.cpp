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
int T, n, a[500001], sum[500005], cc, min[2000001], tag[2000001];
bool vis[500001];
inline void Pushup(int x) { min[x] = std::min(min[x + x], min[x + x + 1]); }
void Pushdown(int x) {
  if (tag[x]) {
    min[x + x] -= tag[x], tag[x + x] += tag[x];
    min[x + x + 1] -= tag[x], tag[x + x + 1] += tag[x];
    tag[x] = 0;
  }
}
void Build(int l, int r, int x) {
  tag[x] = 0;
  if (l == r) {
    min[x] = sum[n] - sum[l - 1] + cc;
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    min[x] -= v, tag[x] += v;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, v, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
  Pushup(x);
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (a[i] == 0);
  int z = sum[n];
  if (z < 2) {
    std::cout << "0\n";
    return;
  }
  int mid = 0;
  for (int i = 1; i <= n; i++)
    if (sum[i] == z / 2) {
      mid = i;
      break;
    }
  std::memset(vis + 1, 0, n);
  for (int i = 1; i <= n; i++) vis[a[i]] = true;
  std::vector<int> fir(n + 1, -1), la(n + 1, -1), pr(n + 1, -1), nx(n + 1, -1);
  for (int i = 1; i <= mid; i++) fir[a[i]] = i;
  for (int i = n; i > mid; i--) la[a[i]] = i;
  cc = 0;
  for (int i = 1; i <= n; i++) cc += vis[i];
  Build(mid + 1, n + 1, 1);
  for (int i = 1, p = 0; i <= n; i++) {
    pr[i] = p;
    if (a[i] == 0) p = i;
  }
  for (int i = n, p = n + 1; i >= 1; i--) {
    nx[i] = p;
    if (a[i] == 0) p = i;
  }
  std::vector<std::vector<int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) continue;
    if (fir[i] == -1)
      Modify(mid + 1, nx[la[i]], mid + 1, n + 1, 1, 1);
    else
      v[pr[fir[i]]].push_back(i);
  }
  int ans = 0x3f3f3f3f;
  for (int i = 0; i <= mid; i++) {
    for (const auto &j : v[i])
      if (la[j] == -1)
        Modify(mid + 1, n + 1, mid + 1, n + 1, 1, 1);
      else
        Modify(mid + 1, nx[la[j]], mid + 1, n + 1, 1, 1);
    checkmin(ans, sum[i] + min[1]);
  }
  std::cout << std::min(ans, z >> 1) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
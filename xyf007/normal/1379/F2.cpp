#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, q;
std::set<int> s[200001][2];
int minl[800001], maxr[800001];
bool ok[800001];
void Pushup(int x) {
  minl[x] = std::min(minl[x + x], minl[x + x + 1]);
  maxr[x] = std::max(maxr[x + x], maxr[x + x + 1]);
  ok[x] = ok[x + x] && ok[x + x + 1] && minl[x + x] > maxr[x + x + 1];
}
void Build(int l, int r, int x) {
  if (l == r) {
    minl[x] = m, maxr[x] = -1, ok[x] = true;
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Update(int l, int r, int p, int x) {
  if (l == r) {
    minl[x] = *s[l][0].begin(), maxr[x] = *s[l][1].rbegin();
    ok[x] = minl[x] > maxr[x];
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    Update(l, mid, p, x + x);
  else
    Update(mid + 1, r, p, x + x + 1);
  Pushup(x);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q;
  for (int i = 0; i < n; i++) s[i][0].emplace(m), s[i][1].emplace(-1);
  Build(0, n - 1, 1);
  while (q--) {
    int x, y;
    std::cin >> x >> y, x--, y--;
    int op = x & 1;
    y >>= 1;
    if (!s[x >> 1][op].count(y)) {
      s[x >> 1][op].emplace(y);
      if ((op == 0 && *s[x >> 1][0].begin() == y) ||
          (op == 1 && *s[x >> 1][1].rbegin() == y))
        Update(0, n - 1, x >> 1, 1);
    } else {
      bool f = (op == 0 && *s[x >> 1][0].begin() == y) ||
               (op == 1 && *s[x >> 1][1].rbegin() == y);
      s[x >> 1][op].erase(y);
      if (f) Update(0, n - 1, x >> 1, 1);
    }
    std::cout << (ok[1] ? "YES\n" : "NO\n");
  }
  return 0;
}
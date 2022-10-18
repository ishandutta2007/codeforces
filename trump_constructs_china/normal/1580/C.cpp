#include <algorithm>
#include <cmath>
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
struct Node {
  long long x, y, l, r;
} a[400001];
struct Fuck {
  long long s, x, y, op;
  Fuck(long long s = 0, long long x = 0, long long y = 0, long long op = 0)
      : s(s), x(x), y(y), op(op) {}
};
std::vector<Fuck> v[400005];
long long n, m, cnt, B, c[400005], d[501][501], x[400001], y[400001];
int mp[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> x[i] >> y[i];
  for (int i = 1; i <= m; i++) {
    int op, k;
    std::cin >> op >> k;
    if (op == 1)
      a[mp[k] = ++cnt] = {x[k], y[k], i, 0};
    else
      a[mp[k]].r = i - 1, mp[k] = 0;
  }
  for (int i = 1; i <= cnt; i++)
    if (!a[i].r) a[i].r = m;
  B = 500;
  for (int i = 1; i <= cnt; i++) {
    auto [x, y, l, r] = a[i];
    if (x + y >= B) {
      for (int i = l; i + x <= r; i += x + y)
        c[i + x]++, c[std::min(i + x + y, r + 1)]--;
    } else {
      v[l].emplace_back(l, x, y, 1), v[r + 1].emplace_back(l, x, y, -1);
    }
  }
  for (int i = 1; i <= m; i++) {
    c[i] += c[i - 1];
    long long ans = c[i];
    for (auto &&[s, x, y, op] : v[i])
      for (int j = s + x; j < s + x + y; j++) d[x + y][j % (x + y)] += op;
    for (int j = 1; j <= 500; j++) ans += d[j][i % j];
    std::cout << ans << '\n';
  }
  return 0;
}
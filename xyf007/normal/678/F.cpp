#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  long long x, y;
  int st, ed;
} a[300001];
int n, m, r[300001], b[300001];
std::vector<int> t[1200001];
bool Check(int x, int y, int z) {
  long long x1 = a[y].x - a[x].x, y1 = a[y].y - a[x].y, x2 = a[z].x - a[y].x,
            y2 = a[z].y - a[y].y;
  return x1 * y2 - x2 * y1 >= 0;
}
void Insert(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    int top = t[x].size();
    while (t[x].size() >= 2 && Check(t[x][top - 2], t[x][top - 1], v))
      t[x].pop_back(), top--;
    t[x].emplace_back(v);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) Insert(L, R, l, mid, v, x + x);
  if (R > mid) Insert(L, R, mid + 1, r, v, x + x + 1);
}
long long ans;
auto slope = [](int x, int y) {
  if (a[y].x == a[x].x) return a[y].y > a[x].y ? 1e10 : -1e10;
  return (a[y].y - a[x].y) / static_cast<double>(a[y].x - a[x].x);
};
void Solve(int l, int r, int p, long long k, int x) {
  if (!t[x].empty()) {
    int top = t[x].size() - 1, l = 0, r = top, best = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      double sl = mid == top ? -1e18 : slope(t[x][mid], t[x][mid + 1]);
      if (sl <= k)
        best = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    checkmax(ans, -k * a[t[x][best]].x + a[t[x][best]].y);
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    Solve(l, mid, p, k, x + x);
  else
    Solve(mid + 1, r, p, k, x + x + 1);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  std::fill(b + 1, b + n + 1, 0x3f3f3f3f);
  for (int i = 1; i <= n; i++) {
    int op;
    std::cin >> op;
    if (op == 1) {
      r[i] = ++m, std::cin >> a[m].x >> a[m].y;
      a[m].st = i;
    } else if (op == 2) {
      int x;
      std::cin >> x;
      a[r[x]].ed = i;
    } else {
      std::cin >> b[i];
    }
  }
  for (int i = 1; i <= m; i++)
    if (!a[i].ed) a[i].ed = n;
  std::sort(a + 1, a + m + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.x < rhs.x; });
  for (int i = 1; i <= m; i++) Insert(a[i].st, a[i].ed, 1, n, i, 1);
  for (int i = 1; i <= n; i++)
    if (b[i] != 0x3f3f3f3f) {
      ans = -4557430888798830400LL;
      Solve(1, n, i, -b[i], 1);
      if (ans == -4557430888798830400LL) {
        std::cout << "EMPTY SET\n";
      } else {
        std::cout << ans << '\n';
      }
    }
  return 0;
}
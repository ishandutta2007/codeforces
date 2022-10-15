#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <deque>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a[20001], f[20001], g[20001], k[20001], b[20001], s[20001], top;
auto ck = [](int x, int y, int z) {
  long long x1 = y - x, y1 = g[y] - g[x], x2 = z - y, y2 = g[z] - g[y];
  return x1 * y2 - x2 * y1 <= 0;
};
std::deque<int> h[20001];
void Merge(int x, int y) {
  if (h[x].size() < h[y].size()) {
    while (!h[x].empty()) {
      while (h[y].size() > 1 && ck(h[x].back(), h[y][0], h[y][1]))
        h[y].pop_front();
      h[y].emplace_front(h[x].back()), h[x].pop_back();
    }
  } else {
    while (!h[y].empty()) {
      while (h[x].size() > 1 && ck(h[x][h[x].size() - 2], h[x].back(), h[y][0]))
        h[x].pop_back();
      h[x].emplace_back(h[y][0]), h[y].pop_front();
    }
    h[y].swap(h[x]);
  }
}
int Calc(int x, int k) {
  int top = h[x].size() - 1, l = 0, r = top, best = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (mid == top ||
        g[h[x][mid + 1]] - g[h[x][mid]] >= k * (h[x][mid + 1] - h[x][mid]))
      best = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  int u = h[x][best];
  return g[u] - k * u;
}
inline int F(int id, int x) { return k[id] * x + b[id]; }
struct Node {
  int ls, rs, v;
} t[2000001];
int tot, rt[20001];
int Modify(int l, int r, int v, int x) {
  int xx = ++tot;
  t[xx] = t[x];
  int mid = (l + r) >> 1;
  if (F(v, mid) < F(t[xx].v, mid)) std::swap(t[xx].v, v);
  if (F(v, l) < F(t[xx].v, l)) t[xx].ls = Modify(l, mid, v, t[x].ls);
  if (F(v, r) < F(t[xx].v, r)) t[xx].rs = Modify(mid + 1, r, v, t[x].rs);
  return xx;
}
int Query(int l, int r, int p, int x) {
  if (x == 0) return 0x3f3f3f3f;
  int ans = F(t[x].v, p);
  if (l == r) return ans;
  int mid = (l + r) >> 1;
  if (p <= mid)
    checkmin(ans, Query(l, mid, p, t[x].ls));
  else
    checkmin(ans, Query(mid + 1, r, p, t[x].rs));
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::fill(g + 1, g + n + 1, 0x3f3f3f3f);
  b[0] = 0x3f3f3f3f;
  while (m--) {
    for (int i = 1; i <= n; i++) std::deque<int>(1, i - 1).swap(h[i]);
    for (int i = 1; i <= tot; i++) t[i].ls = t[i].rs = t[i].v = 0;
    tot = top = 0;
    for (int i = 1; i <= n; i++) {
      while (top && a[s[top]] <= a[i]) Merge(s[top--], i);
      k[i] = a[i], b[i] = Calc(i, a[i]);
      rt[i] = Modify(1, n, i, rt[s[top]]);
      f[i] = Query(1, n, i, rt[i]);
      s[++top] = i;
    }
    std::swap(f, g);
  }
  std::cout << g[n];
  return 0;
}
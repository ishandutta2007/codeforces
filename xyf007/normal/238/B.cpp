#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
struct Node {
  int v, pos;
} a[100001];
int n, h, b[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].v;
    a[i].pos = i;
  }
  std::sort(a + 1, a + n + 1,
            [](const Node &x, const Node &y) -> bool { return x.v < y.v; });
  int p = -1, ans = 0x7fffffff;
  for (int i = 0; i <= n; i++) {
    int t1 = i > 1 ? a[1].v + a[2].v : 300000000,
        t2 = i < n - 1 ? a[i + 1].v + a[i + 2].v : 300000000,
        t3 = i && (i < n) ? a[1].v + a[i + 1].v + h : 300000000,
        min = std::min({t1, t2, t3}),
        t4 = i > 1 ? a[i].v + a[i - 1].v : 0,
        t5 = i < n - 1 ? a[n].v + a[n - 1].v : 0,
        t6 = i && (i < n) ? a[i].v + a[n].v + h : 0,
        max = std::max({t4, t5, t6});
    if (max - min < ans) {
      ans = max - min;
      p = i;
    }
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= p; i++) {
    b[a[i].pos] = 1;
  }
  for (int i = p + 1; i <= n; i++) {
    b[a[i].pos] = 2;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << b[i] << ' ';
  }
  return 0;
}
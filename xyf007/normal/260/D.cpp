#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
int n, c[100001], s[100001], fa[100001], b[100001], w[100001];
std::vector<std::pair<int, int>> a[2];
std::vector<std::tuple<int, int, int>> ans;
int Find(int x) {
  if (x == fa[x]) {
    return x;
  }
  return fa[x] = Find(fa[x]);
}
void Merge(int x, int y) {
  int fx = Find(x), fy = Find(y);
  fa[fx] = fy;
  if (!b[fy]) {
    b[fy] = b[fx];
  }
  if (!w[y]) {
    w[fy] = w[fx];
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    std::cin >> c[i] >> s[i];
    a[c[i]].emplace_back(s[i], i);
    if (c[i]) {
      b[i] = i;
    } else {
      w[i] = i;
    }
  }
  std::size_t p0 = 0, p1 = 0;
  while (p0 < a[0].size() && p1 < a[1].size()) {
    if (a[0][p0].first == a[1][p1].first) {
      ans.emplace_back(a[0][p0].second, a[1][p1].second, a[0][p0].first);
      Merge(a[0][p0++].second, a[1][p1++].second);
    } else if (a[0][p0].first < a[1][p1].first) {
      ans.emplace_back(a[0][p0].second, a[1][p1].second, a[0][p0].first);
      Merge(a[0][p0].second, a[1][p1].second);
      a[1][p1].first -= a[0][p0++].first;
    } else {
      ans.emplace_back(a[0][p0].second, a[1][p1].second, a[1][p1].first);
      Merge(a[0][p0].second, a[1][p1].second);
      a[0][p0].first -= a[1][p1++].first;
    }
  }
  int rt = Find(1);
  for (int i = 2; i <= n; i++) {
    int fi = Find(i);
    if (fi != rt) {
      if (b[fi] && w[rt]) {
        ans.emplace_back(b[fi], w[rt], 0);
      } else {
        ans.emplace_back(w[fi], b[rt], 0);
      }
      Merge(fi, rt);
    }
  }
  for (auto &&i : ans) {
    std::cout << std::get<0>(i) << ' ' << std::get<1>(i) << ' ' << std::get<2>(i) << '\n';
  }
  return 0;
}
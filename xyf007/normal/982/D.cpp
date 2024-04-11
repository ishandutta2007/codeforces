#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
int n, a[100001], b[100001], c[100001], fa[100001], sz[100001];
std::vector<int> p[100001];
bool vis[100001];
std::multiset<int> s;
int Find(int x) {
  if (x == fa[x]) {
    return x;
  }
  return fa[x] = Find(fa[x]);
}
void Merge(int x, int y) {
  int fx = Find(x), fy = Find(y);
  if (fx == fy) {
    return;
  }
  sz[fy] += sz[fx];
  fa[fx] = fy;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::memcpy(b + 1, a + 1, 4 * n);
  std::sort(b + 1, b + n + 1);
  int nn = std::unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    int pos = std::lower_bound(b + 1, b + nn + 1, a[i]) - b;
    c[pos] = a[i];
    p[a[i] = pos].emplace_back(i);
  }
  int ans = -1;
  size_t max = 0;
  for (int i = 1; i <= nn; i++) {
    for (auto &&j : p[i]) {
      fa[j] = j;
      sz[j] = 1;
      vis[j] = true;
      if (j > 1 && vis[j - 1]) {
        s.erase(s.find(sz[Find(j - 1)]));
        Merge(j - 1, j);
      }
      if (j < n && vis[j + 1]) {
        s.erase(s.find(sz[Find(j + 1)]));
        Merge(j + 1, j);
      }
      s.emplace(sz[j]);
    }
    if (*s.begin() == *s.rbegin()) {
      if (s.size() > max) {
        max = s.size();
        ans = c[i] + 1;
      }
    }
  }
  std::cout << ans;
  return 0;
}
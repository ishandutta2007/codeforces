#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int k, n, m, l, a[100001], t[100001], dp[100001];
bool vis[100001];
void checkmax(int &x, int y) {
  if (x < y) {
    x = y;
  }
}
void Add(int x, int v) {
  while (x <= m) {
    checkmax(t[x], v);
    x += x & -x;
  }
}
int Query(int x) {
  int s = 0;
  while (x) {
    checkmax(s, t[x]);
    x -= x & -x;
  }
  return s;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> k >> n >> m >> l;
  while (k--) {
    std::memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      vis[a[i]] = true;
    }
    int tot = std::count(vis + 1, vis + m + 1, true);
    if (l >= tot) {
      std::cout << tot << '\n';
      continue;
    }
    std::memset(t, 0, sizeof(t));
    std::memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= l; i++) {
      for (int j = 1; j <= n; j++) {
        int tmp = Query(a[j] - 1) + 1;
        if (tmp > dp[j]) {
          checkmax(ans, dp[j] = tmp);
          Add(a[j], tmp);
        }
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
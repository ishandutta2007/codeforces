#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
struct Mate {
  int l, r, v, id;
} b[401];
int n, m, v, a[401], dp[401][401], pre[401][401];
std::vector<Mate> c[401];
int main(int argc, char const *argv[]) {
#ifdef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
  std::freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> v;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i].l >> b[i].r >> b[i].v;
    b[i].id = i;
    for (int j = b[i].l; j <= b[i].r; j++) {
      c[j].emplace_back(b[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    std::sort(
        c[i].begin(), c[i].end(),
        [](const Mate &lhs, const Mate &rhs) -> bool { return lhs.v < rhs.v; });
  }
  std::memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 400; j++) {
      if (j + a[i] < v || dp[i - 1][j] == -1) {
        continue;
      }
      if (j >= v) {
        if (dp[i][a[i]] < dp[i - 1][j]) {
          dp[i][a[i]] = dp[i - 1][j];
          pre[i][a[i]] = j;
        }
      } else {
        if (dp[i][j + a[i] - v] < dp[i - 1][j]) {
          dp[i][j + a[i] - v] = dp[i - 1][j];
          pre[i][j + a[i] - v] = j;
        }
      }
      int s = 0;
      for (int k = 0; k < static_cast<int>(c[i].size()); k++) {
        if (j + a[i] >= v + s + c[i][k].v) {
          s += c[i][k].v;
          if (j >= v + s) {
            if (dp[i][a[i]] < dp[i - 1][j] + k + 1) {
              dp[i][a[i]] = dp[i - 1][j] + k + 1;
              pre[i][a[i]] = j;
            }
          } else {
            if (dp[i][j + a[i] - v - s] < dp[i - 1][j] + k + 1) {
              dp[i][j + a[i] - v - s] = dp[i - 1][j] + k + 1;
              pre[i][j + a[i] - v - s] = j;
            }
          }
        }
      }
    }
  }
  int rm = std::max_element(dp[n], dp[n] + 401) - dp[n], ans = dp[n][rm];
  std::cout << ans << '\n';
  std::vector<int> sol[401];
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < dp[i][rm] - dp[i - 1][pre[i][rm]]; j++) {
      sol[i].emplace_back(c[i][j].id);
    }
    rm = pre[i][rm];
  }
  for (int i = 1; i <= n; i++) {
    std::cout << sol[i].size();
    for (auto &&j : sol[i]) {
      std::cout << ' ' << j;
    }
    std::cout << '\n';
  }
  return 0;
}
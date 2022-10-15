#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int l, r, n, p[26], tot, a[3000001], cnt, dp[3000001];
bool not_prime[101], vis[3000001];
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
void Init(int n) {
  not_prime[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!not_prime[i]) {
      p[++tot] = i;
    }
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      not_prime[i * p[j]] = true;
      if (!(i % p[j])) {
        break;
      }
    }
  }
}
void Dfs(int now, int s) {
  a[++cnt] = s;
  for (int i = now; i <= tot; i++) {
    if (static_cast<long long>(s) * p[i] > r) {
      break;
    }
    Dfs(i, s * p[i]);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> l >> r >> n;
  Init(n);
  Dfs(1, 1);
  std::sort(a + 1, a + cnt + 1);
  std::memset(dp, 0x3f, sizeof(dp));
  dp[1] = 0;
  vis[1] = true;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    int k = 1;
    for (int j = 1; j <= cnt; j++) {
      if (static_cast<long long>(a[j]) * i > r) {
        break;
      }
      while (a[k] < a[j] * i) {
        k++;
      }
      checkmin(dp[k], dp[j] + 1);
      if (a[k] >= l && !vis[k]) {
        if (dp[k] + i <= n) {
          vis[k] = true;
          ans++;
        }
      }
    }
  }
  std::cout << ans;
  return 0;
}
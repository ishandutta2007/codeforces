#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
int n, m, k, a[401][401], sum[401][401], tmp[26];
char s[401][401];
int Query(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main(int argc, char const *argv[]) {
#if defined(ONLINE_JUDGE)
  std::freopen("input.txt", "r", stdin);
  std::freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> (s[i] + 1);
    for (int j = 1; j <= m; j++) {
      a[i][j] = s[i][j] == 'a';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
  }
  long long ans = 0LL;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      std::memset(tmp, 0, sizeof(tmp));
      int cnt = 0, r = 0;
      for (int l = 1; l <= m; l++) {
        while (r < m && (cnt + Query(i, r + 1, j, r + 1) <= k || r < l)) {
          r++;
          cnt += Query(i, r, j, r);
          if (s[i][r] == s[j][r]) {
            tmp[s[i][r] - 'a']++;
          }
        }
        if (s[i][l] == s[j][l]) {
          tmp[s[i][l] - 'a']--;
          if (cnt <= k) {
            ans += tmp[s[i][l] - 'a'];
          }
        }
        cnt -= Query(i, l, j, l);
      }
    }
  }
  std::cout << ans;
  return 0;
}
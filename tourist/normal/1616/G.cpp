/**
 *    author:  tourist
 *    created: 29.12.2021 19:58:27       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> line(n - 1, 0);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (y == x + 1) {
        line[x] = 1;
      } else {
        g[x].push_back(y);
      }
    }
    int lines = accumulate(line.begin(), line.end(), 0);
    if (lines == n - 1) {
      cout << (long long) n * (n - 1) / 2 << '\n';
      continue;
    }
    vector<int> limit(n);
    limit[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
      if (line[i]) {
        limit[i] = limit[i + 1];
      } else {
        limit[i] = i;
      }
    }
    vector<vector<int>> f(n - 1);
    vector<vector<int>> fr(n - 1);
    for (int i = 0; i < n - 1; i++) {
      for (int j : g[i]) {
        if (j >= i + 2 && limit[i + 1] >= j - 1) {
          f[i].push_back(j - 1);
          fr[j - 1].push_back(i);
        }
      }
    }
    int cut = -1;
    for (int i = 0; i < n - 1; i++) {
      if (line[i] == 0) {
        cut = i;
        break;
      }
    }
    assert(cut != -1);
    vector<vector<int>> dp(n - 1, vector<int>(2, 0));
    dp[cut][0] = 1;
    for (int i = cut; i < n - 1; i++) {
      for (int j : f[i]) {
        dp[j][0] |= dp[i][1];
        dp[j][1] |= dp[i][0];
      }
    }
    vector<vector<int>> dp_rev(n - 1, vector<int>(2, 0));
    dp_rev[cut][0] = 1;
    for (int i = cut; i >= 0; i--) {
      for (int j : fr[i]) {
        dp_rev[j][0] |= dp_rev[i][1];
        dp_rev[j][1] |= dp_rev[i][0];
      }
    }
    vector<long long> cntL(4, 0);
    for (int i = 0; i <= cut; i++) {
      int mask = dp_rev[i][0] + 2 * dp_rev[i][1];
      cntL[mask] += 1;
    }
    vector<long long> cntR(4, 0);
    for (int i = n - 2; i >= 0; i--) {
      int mask = dp[i][0] + 2 * dp[i][1];
      cntR[mask] += 1;
      if (line[i] == 0) {
        break;
      }
    }
    long long ans = 0;
    for (int x = 1; x < 4; x++) {
      for (int y = 1; y < 4; y++) {
        if (((x & 1) && (y & 1)) || ((x & 2) && (y & 2))) {
          ans += cntL[x] * cntR[y];
        }
      }
    }
    ans += (ans > 0);
    for (int x = 1; x < 4; x++) {
      for (int y = 1; y < 4; y++) {
        if (cntR[y] > 0) {
          if (((x & 1) && (y & 2)) || ((x & 2) && (y & 1))) {
            ans += cntL[x];
            break;
          }
        }
      }
    }
    for (int x = 1; x < 4; x++) {
      for (int y = 1; y < 4; y++) {
        if (cntL[y] > 0) {
          if (((x & 1) && (y & 2)) || ((x & 2) && (y & 1))) {
            ans += cntR[x];
            break;
          }
        }
      }
    }
    ans -= (lines == n - 2);
    cout << ans << '\n';
  }
  return 0;
}
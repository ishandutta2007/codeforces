/**
 *    author:  tourist
 *    created: 13.08.2022 18:10:43       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    --p[i];
    g[p[i]].push_back(i);
    g[i].push_back(p[i]);
  }
  vector<int> h(n);
  for (int i = n - 1; i > 0; i--) {
    h[p[i]] = max(h[p[i]], h[i] + 1);
  }
  vector<int> a(n, -1);
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (g[i].size() == 1) {
      a[i] = 0;
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    for (int u : g[que[b]]) {
      if (a[u] == -1) {
        que.push_back(u);
        a[u] = a[que[b]] + 1;
      }
    }
  }
  int tt;
  cin >> tt;
  vector<int> weight(tt);
  vector<int> ans(tt);
  for (int qq = 0; qq < tt; qq++) {
    cin >> weight[qq];
  }
  vector<vector<int>> dp(n);
  for (int i = n - 1; i >= 0; i--) {
    int cur = 0;
    dp[i].assign(1, a[i]);
    for (int j : g[i]) {
      if (j > i) {
        if (cur <= h[j]) {
          for (int qq = 0; qq < tt; qq++) {
            int low = 0, high = cur + h[j] + 1;
            while (low < high) {
              int mid = (low + high + 1) >> 1;
              bool found = false;
              int L = max(0, mid - 1 - h[j]);
              int R = min(cur, mid - 1);
              for (int x = L; x <= R; x++) {
                int y = mid - 1 - x;
                if (dp[i][cur - x] + dp[j][h[j] - y] + weight[qq] >= mid) {
                  found = true;
                  break;
                }
              }
              if (found) {
                low = mid;
              } else {
                high = mid - 1;
              }
            }
            ans[qq] = max(ans[qq], low);
          }
          dp[j].push_back(max(dp[j][h[j]], dp[i][cur]));
          for (int y = 0; y <= cur - 1; y++) {
            dp[j][h[j] - y] = max(dp[j][h[j] - y], dp[i][cur - (y + 1)]);
          }
          swap(dp[i], dp[j]);
          cur = h[j] + 1;
        } else {
          for (int qq = 0; qq < tt; qq++) {
            int low = 0, high = cur + h[j] + 1;
            while (low < high) {
              int mid = (low + high + 1) >> 1;
              bool found = false;
              int L = max(0, mid - 1 - cur);
              int R = min(h[j], mid - 1);
              for (int y = L; y <= R; y++) {
                int x = mid - 1 - y;
                if (dp[i][cur - x] + dp[j][h[j] - y] + weight[qq] >= mid) {
                  found = true;
                  break;
                }
              }
              if (found) {
                low = mid;
              } else {
                high = mid - 1;
              }
            }
            ans[qq] = max(ans[qq], low);
          }
          dp[i][cur - 0] = max(dp[i][cur - 0], dp[j][h[j] - 0]);
          for (int y = 0; y <= h[j]; y++) {
            dp[i][cur - (y + 1)] = max(dp[i][cur - (y + 1)], dp[j][h[j] - y]);
          }
        }
      }
    }
  }
  for (int qq = 0; qq < tt; qq++) {
    cout << ans[qq] << " \n"[qq == tt - 1];
  }
  debug(clock());
  return 0;
}
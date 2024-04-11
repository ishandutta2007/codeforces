/**
 *    author:  tourist
 *    created: 01.11.2020 17:14:09       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n);
  vector<int> sz(n);
  vector<long long> sum(n);
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    a[i].resize(foo);
    sz[i] = foo;
    sum[i] = 0;
    for (int j = 0; j < foo; j++) {
      cin >> a[i][j];
      sum[i] += a[i][j];
    }
  }
  const long long inf = (long long) 1e18;
  vector<vector<long long>> save(30, vector<long long>(k + 1, -inf));
  vector<long long> dp(k + 1, -inf);
  dp[0] = 0;
  long long ans = 0;
  function<void(int, int, int)> Solve = [&](int level, int from, int to) {
    if (from == to) {
      long long took = 0;
      for (int i = 0; i <= k; i++) {
        ans = max(ans, took + dp[k - i]);
        if (i == (int) a[from].size()) {
          break;
        }
        took += a[from][i];
      }
      return;
    }
    for (int j = 0; j <= k; j++) {
      save[level][j] = dp[j];
    }
    int mid = (from + to) >> 1;
    {
      for (int i = from; i <= mid; i++) {
        for (int j = k - sz[i]; j >= 0; j--) {
          dp[j + sz[i]] = max(dp[j + sz[i]], dp[j] + sum[i]);
        }
      }
      Solve(level + 1, mid + 1, to);
      for (int j = 0; j <= k; j++) {
        dp[j] = save[level][j];
      }
    }
    {
      for (int i = mid + 1; i <= to; i++) {
        for (int j = k - sz[i]; j >= 0; j--) {
          dp[j + sz[i]] = max(dp[j + sz[i]], dp[j] + sum[i]);
        }
      }
      Solve(level + 1, from, mid);
      for (int j = 0; j <= k; j++) {
        dp[j] = save[level][j];
      }
    }
  };
  Solve(0, 0, n - 1);
  cout << ans << '\n';
  return 0;
}
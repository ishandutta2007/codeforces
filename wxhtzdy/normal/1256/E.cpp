/**
 *  author: milos
 *  created: 12.01.2021 01:42:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j){
    return a[i] < a[j];
  });
  const long long inf = (long long) 1e18;
  vector<long long> dp(n + 6, inf);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    if ((i + 2) < n) dp[i + 3] = min(dp[i + 3], dp[i] + a[order[i + 2]] - a[order[i]]);
    if ((i + 3) < n) dp[i + 4] = min(dp[i + 4], dp[i] + a[order[i + 3]] - a[order[i]]);
    if ((i + 4) < n) dp[i + 5] = min(dp[i + 5], dp[i] + a[order[i + 4]] - a[order[i]]);
  }
  int x = n;
  vector<int> p(n + 1);
  p[0] = 0;
  while (x > 2) {
    if (dp[x] == dp[x - 3] + a[order[x - 1]] - a[order[x - 3]]) {
      p[x] = x - 3;
      x = x - 3;
    } else {
      if (dp[x] == dp[x - 4] + a[order[x - 1]] - a[order[x - 4]]) {
        p[x] = x - 4;
        x = x - 4;
      } else {
        p[x] = x - 5;
        x = x - 5;
      }
    }
  }
  vector<int> pos;
  pos.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (p[i] != 0) {
      pos.push_back(p[i]);
    }
  }
  cout << dp[n] << " " << pos.size() << '\n';
  vector<int> ans(n, 1);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j < (int) pos.size() && pos[j] == i) {
      j += 1; 
    }
    ans[i] = j;
  }
  vector<int> actual_ans(n);
  for (int i = 0; i < n; i++) {
    actual_ans[order[i]] = ans[i];  
  }
  for (int i = 0; i < n; i++) {
    cout << actual_ans[i] << " ";
  }
  return 0;
}
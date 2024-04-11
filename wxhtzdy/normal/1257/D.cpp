/**
 *    author:  milos
 *    created: 14.02.2021 19:17:43       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> p(m), s(m);
    vector<int> dp(n + 1, 0);
    vector<int> mx(n + 1, 0);
    for (int i = 0; i < m; i++) {
      cin >> p[i] >> s[i];
      mx[s[i]] = max(mx[s[i]], p[i]);
    }      
    for (int i = n; i >= 1; i--) {
      if (i < n) {       
        dp[i] = dp[i + 1];
      }
      dp[i] = max(dp[i], mx[i]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] > dp[1]) {
        ok = false;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    int cnt = 0, ans = 1;
    int curr = 0;
    for (int i = 0; i < n; i++) {
      cnt++;
      curr = max(curr, a[i]);
      if (curr > dp[cnt]) {
        ans++;
        cnt = 1;
        curr = a[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
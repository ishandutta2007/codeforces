/**
 *    author:  tourist
 *    created: 02.02.2020 17:03:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> what(m);
    for (int x = 0; x < m; x++) {
      int y = m - 1 - x;
      what[x] = max(a[x], a[n - 1 - y]);
    }
    k = min(k, m - 1);
    int ans = 0;
    for (int fix = 0; fix <= k; fix++) {
      int fiy = k - fix;
      int mn = (int) 2e9;
      for (int i = fix; i <= m - 1 - fiy; i++) {
        mn = min(mn, what[i]);
      }
      ans = max(ans, mn);
    }
    cout << ans << '\n';
  }
  return 0;
}
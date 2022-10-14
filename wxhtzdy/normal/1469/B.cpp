/**
 *  author: milos
 *  created: 28.12.2020 15:45:50
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
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      mx = max(mx, sum);
    }
    int m;
    cin >> m;
    vector<int> b(m);
    int ans = max(0, mx);
    sum = 0;
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      sum += b[i];
      ans = max(ans, sum + mx);
    }
    cout << ans << '\n';
  }
  return 0;
}
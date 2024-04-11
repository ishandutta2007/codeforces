/**
 *    author:  tourist
 *    created: 30.09.2020 17:48:42       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<int> c(m), d(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }
  const int MAX = 1000010;
  vector<int> v(MAX);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] <= c[j]) {
        v[c[j] - a[i]] = max(v[c[j] - a[i]], d[j] - b[i] + 1);
      }
    }
  }
  int ans = 2 * MAX;
  int mx = 0;
  for (int dx = MAX - 1; dx >= 0; dx--) {
    mx = max(mx, v[dx]);
    ans = min(ans, dx + mx);
  }
  cout << ans << '\n';
  return 0;
}
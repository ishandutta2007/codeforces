#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }
  const int MAX = 1e6 + 5;
  vector<int> v(MAX, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] <= c[j]) {
        v[c[j] - a[i]] = max(v[c[j] - a[i]], d[j] - b[i] + 1);
      }
    }
  }
  int ans = 1e9, mx = 0;
  for (int i = MAX - 1; i >= 0; i--) {
    mx = max(mx, v[i]);
    ans = min(ans, mx + i);
  }
  cout << ans << '\n';
  return 0;
}
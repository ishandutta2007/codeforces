/**
 *  author: milos
 *  created: 09.01.2021 07:00:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n), z(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  int m;
  cin >> m;
  vector<int> a(m), b(m), c(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long curr = 1e18;
    for (int j = 0; j < m; j++) {
      if (a[j] < z[i]) {
        continue;
      }
      long long l = a[j] / z[i] * b[j];
      long long tmp = (2 * x[i] + 2 * y[i] + l - 1) / l;
      curr = min(curr, tmp * c[j]);
    }
    ans += curr;
  }
  cout << ans << '\n';
  return 0;
}
/**
 *    author:  tourist
 *    created: 10.03.2021 15:00:29       
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
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < 2 * n; i++) {
      int u, v;
      cin >> u >> v;
      if (u == 0) {
        y.push_back(abs(v));
      } else {
        x.push_back(abs(u));
      }
    }
    assert((int) x.size() == n);
    assert((int) y.size() == n);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += sqrt(x[i] * 1LL * x[i] + y[i] * 1LL * y[i]);
    }
    cout << fixed << setprecision(17) << ans << '\n';
  }
  return 0;
}
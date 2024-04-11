/**
 *    author:  tourist
 *    created: 29.08.2021 17:36:22       
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
      a[i] %= 2;
    }
    const long long inf = (long long) 1e18;
    long long ans = inf;
    for (int r = 0; r < 2; r++) {
      vector<int> x;
      vector<int> y;
      for (int i = r; i < n; i += 2) {
        x.push_back(i);
      }
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          y.push_back(i);
        }
      }
      if (x.size() == y.size()) {
        long long cur = 0;
        for (int i = 0; i < (int) x.size(); i++) {
          cur += abs(x[i] - y[i]);
        }
        ans = min(ans, cur);
      }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}
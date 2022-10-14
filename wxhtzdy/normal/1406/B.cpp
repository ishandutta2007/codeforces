/**
 *  author: milos
 *  created: 07.01.2021 18:26:31
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    const long long inf = 1e18;
    long long ans = -inf, p = 1;
    for (int i = 0; i <= 5; i++) {
      long long r = 1;
      for (int j = n - 1; j >= 0; j--) {
        if (n - j - 1 + i >= 5) {
          break;
        }
        r *= a[j];
      }
      if (i == 0) ans = max(ans, r);
      else ans = max(ans, p * r);
      if (i < 5) {
        p *= a[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
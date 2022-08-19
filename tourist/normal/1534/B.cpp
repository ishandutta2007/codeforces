/**
 *    author:  tourist
 *    created: 13.06.2021 18:37:22       
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
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += abs(a[i] - a[i + 1]);
    }
    ans += a[0];
    ans += a[n - 1];
    for (int i = 0; i < n; i++) {
      int x = a[i] - max(i > 0 ? a[i - 1] : 0, i < n - 1 ? a[i + 1] : 0);
      ans -= max(x, 0);
    }
    cout << ans << '\n';
  }
  return 0;
}
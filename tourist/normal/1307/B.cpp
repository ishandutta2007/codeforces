/**
 *    author:  tourist
 *    created: 17.02.2020 18:36:33       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int ans = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == x) {
        ans = 1;
      }
    }
    if (ans == -1) {
      int mx = *max_element(a.begin(), a.end());
      ans = max(2, (x + mx - 1) / mx);
    }
    cout << ans << '\n';
  }
  return 0;
}
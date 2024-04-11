/**
 *    author:  tourist
 *    created: 30.07.2021 17:39:02       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    vector<int> pref(m + 1);
    for (int i = 0; i < m; i++) {
      pref[i + 1] = pref[i] + b[i];
    }
    vector<int> suf(m + 1);
    for (int i = m - 1; i >= 0; i--) {
      suf[i] = suf[i + 1] + a[i];
    }
    int ans = (int) 1e9;
    for (int i = 0; i < m; i++) {
      ans = min(ans, max(pref[i], suf[i + 1]));
    }
    cout << ans << '\n';
  }
  return 0;
}
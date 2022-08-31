/**
 *    author:  tourist
 *    created: 10.10.2020 17:49:51       
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
    int s = accumulate(a.begin(), a.end(), 0);
    if (s == 0) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    sort(a.begin(), a.end());
    bool ok = true;
    int pref = 0;
    for (int i = 0; i < n; i++) {
      pref += a[i];
      if (pref == 0) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << '\n';
  }
  return 0;
}
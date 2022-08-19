/**
 *    author:  tourist
 *    created: 23.04.2020 17:42:42       
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
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      pos[a[i]] = i;
    }
    bool ok = true;
    int at = 0;
    while (at < n) {
      int j = pos[at];
      int cnt = n - at - j;
      for (int k = j; k < j + cnt; k++) {
        if (a[k] != at) {
          ok = false;
          break;
        }
        at += 1;
      }
      if (!ok) {
        break;
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
  return 0;
}
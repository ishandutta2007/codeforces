/**
 *  author: milos
 *  created: 11.12.2020 00:19:49
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
    bool ok = false;
    for (int i = 1; i < n; i++) {
      if (abs(a[i] - a[i - 1]) >= 2) {
        cout << "YES" << '\n' << i << " " << i + 1 << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';  
    }
  }
  return 0;
}
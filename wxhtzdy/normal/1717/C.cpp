/**
 *    author:  wxhtzdy
 *    created: 07.09.2022 18:52:25
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<bool> f(n);
    for (int i = 0; i < n; i++) {
      f[i] = (a[i] == b[i]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (f[(i - 1 + n) % n]) {
        if (a[i] > b[i]) {
          ok = false;
        }
        continue;
      }
      if (b[i] < max(a[i], b[(i - 1 + n) % n] - 1)) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                  
  return 0;
}
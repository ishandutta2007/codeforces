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
    bool p = false;
    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        p = true;
      }
    }
    if (p) {
      int cc = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          cc += 1;
        }
      }
      cout << cc << '\n';
      continue;
    }
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
      int x = a[i];
      int ft = 0;
      while (x % 2 == 0) {
        ft += 1;
        x /= 2;
      }
      mn = min(mn, ft);
    }
    cout << mn + n - 1 << '\n';
  }
  return 0;
}
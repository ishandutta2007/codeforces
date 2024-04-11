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
    vector<int> b;
    int xr = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b.push_back(a[i]);
      xr ^= a[i];
    }
    b.push_back(xr);
    bool ok = false;
    for (int i = 0; i < n + 1; i++) {
      int x = a[0], cnt = 0;
      if (x == b[i]) {
        x = 0;
        cnt++;
      }
      for (int j = 1; j < n; j++) {
        x ^= a[j];
        if (x == b[i]) {
          cnt++;
          x = 0;
        }
      }
      if (x == 0 && cnt > 1) {
        cout << "YES" << '\n';
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
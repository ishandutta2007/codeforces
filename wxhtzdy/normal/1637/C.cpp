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
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i != 0 && i != n - 1) {
        ans += (a[i] + 1) / 2;
      }    
    }
    if (n == 3) {
      if (a[1] % 2 == 1) {
        cout << -1 << '\n';
      } else {
        cout << a[1] / 2 << '\n';
      }
      continue;
    }
    bool ok = false;
    for (int i = 1; i + 1 < n; i++) {
      if (a[i] >= 2) {
        ok = true;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }                                                     
  return 0;
}
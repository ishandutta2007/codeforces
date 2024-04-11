/**
 *    author:  wxhtzdy
 *    created: 16.10.2022 16:46:33
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      int cc = 0;
      while (a[i] % 2 == 0) {
        cc += 1;
        a[i] /= 2;
      }
      a[i] = cc;
      int x = i + 1;
      while (x % 2 == 0) {
        b[i] += 1;
        x /= 2;
      }
    }
    int s = accumulate(a.begin(), a.end(), 0);
    int ans = 0;
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; i++) {
      if (s < n) {
        ans += 1;
        s += b[i];
      }
    }  
    if (s < n) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }                                                                    
  return 0;
}
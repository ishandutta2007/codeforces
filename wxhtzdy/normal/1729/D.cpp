/**
 *    author:  wxhtzdy
 *    created: 12.09.2022 16:57:34
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
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
      cin >> y[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = y[i] - x[i];
    }    
    sort(a.rbegin(), a.rend());
    int ptr = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i >= ptr) {
        break;
      }
      long long s = a[i];
      if (a[i] + a[ptr] >= 0) {
        ptr--;
        ans += 1;
        continue;
      }             
      while (ptr > i && a[ptr] + a[i] < 0) {
        ptr -= 1;
      }
      if (a[ptr] + a[i] >= 0 && i < ptr) {
        ptr--;
        ans += 1;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}
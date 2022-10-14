/**
 *    author:  wxhtzdy
 *    created: 08.07.2022 18:22:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < m; i++) {
      b[a[i]] += 1;
    }                    
    int low = 0, high = 2 * m, ans = 0;
    while (low <= high) {
      int mid = low + high >> 1;
      long long x = 0;
      long long y = 0;          
      for (int i = 0; i < n; i++) {
        int d = mid - b[i];
        if (d >= 0) {
          x += d / 2;
        } else {
          y -= d;
        }
      }
      if (x < y) {
        low = mid + 1;
      } else {
        ans = mid;
        high = mid - 1;        
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}
/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 17:09:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }      
    vector<int> f(n, 1);
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] * 2 <= a[i]) {
        f[i] = 0;
      }
    }
    int s = 0;                
    for (int i = 0; i < k; i++) {
      s += f[i];
    }
    int ans = 0;
    ans += (s == k);
    for (int i = 0; i < n - k - 1; i++) {
      s -= f[i];
      s += f[i + k];
      if (s == k) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}
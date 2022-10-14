/**
 *    author:  wxhtzdy
 *    created: 06.02.2022 23:17:41
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
    if (k == 1) {
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i++) {
        cout << i << '\n';
      }
    } else {      
      if (n % 2 == 1) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
          cout << i + (j - 1) * n << " ";
        }
        cout << '\n';
      }
    }
  }                                                                    
  return 0;
}
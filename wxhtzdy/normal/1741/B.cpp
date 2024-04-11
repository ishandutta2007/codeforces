/**
 *    author:  wxhtzdy
 *    created: 11.10.2022 16:38:59
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
    if (n == 3) {
      cout << -1 << '\n';
    } else {   
      if (n % 2 == 0) {
        for (int i = 1; i <= n; i += 2) {
          cout << i + 1 << " " << i << " ";
        }
        cout << '\n';
      } else {  
        cout << n << " " << n - 1 << " ";
        for (int i = 1; i <= n - 2; i++) {
          cout << i << " ";
        } 
        cout << '\n';
      }
    }
  }                                                                    
  return 0;
}
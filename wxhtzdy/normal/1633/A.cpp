/**
 *    author:  wxhtzdy
 *    created: 01.02.2022 09:14:37
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
    if (n % 7 == 0) {
      cout << n << '\n';
    } else {
      int x = n + (7 - (n % 7));
      int y = n - (n % 7);
      if (x % 10 > n % 10) {
        cout << x << '\n';
      } else {
        cout << y << '\n';
      }
    }
  }                                                                    
  return 0;
}
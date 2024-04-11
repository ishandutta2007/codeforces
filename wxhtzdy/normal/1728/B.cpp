/**
 *    author:  wxhtzdy
 *    created: 08.09.2022 16:37:17
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
    if (n % 2 == 0) {
      for (int i = n - 2; i >= 1; i--) {
        cout << i << " ";
      }
      cout << n - 1 << " " << n << '\n';
    } else {  
      cout << 1 << " " << 2 << " " << 3 << " ";
      for (int i = n - 2; i >= 4; i--) {
        cout << i << " ";
      }
      cout << n - 1 << " " << n << '\n';
    }
  }                                                                    
  return 0;
}
/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 16:33:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c) {
      cout << "YES" << '\n';
    } else if (a + b == c) {
      cout << "YES" << '\n';
    } else if (a + c == b) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n'; 
    }
  }                                                                    
  return 0;
}
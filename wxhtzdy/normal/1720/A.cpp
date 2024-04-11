/**
 *    author:  wxhtzdy
 *    created: 18.08.2022 15:30:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) { 
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d == b * c) {
      cout << 0 << '\n';
    } else {
      if (min(a * d, b * c) == 0 || max(a * d, b * c) % min(a * d, b * c) == 0) {
        cout << 1 << '\n';
      } else {
        cout << 2 << '\n';
      }
    }
  }                                                                
  return 0;
}
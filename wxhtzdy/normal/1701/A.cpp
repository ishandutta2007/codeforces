/**
 *    author:  wxhtzdy
 *    created: 08.07.2022 18:17:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s = a + b + c + d;
    cout << (s == 0 ? 0 : (s < 4 ? 1 : 2)) << '\n';
  }                                                                    
  return 0;
}
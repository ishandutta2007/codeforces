/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 16:34:06
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
    int ans = 0;
    if (a > b) {
      ans += 1;
    }
    if (a > c) {
      ans += 1;
    }
    if (a > d) {
      ans += 1;
    }
    cout << 3 - ans << '\n';
  }                                                                    
  return 0;
}
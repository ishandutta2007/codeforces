/**
 *    author:  milos
 *    created: 12.02.2021 20:22:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    auto Calc = [&](int x, int y) {
      if (y == 1) {
        return 1000000;
      }
      int cnt = 0;
      while (x > 0) {
        x = x / y;
        cnt++;
      }
      return cnt;
    };
    while (Calc(a, b) - Calc(a, b + 1) >= 1) {
      ans += 1;
      b += 1;  
    }
    ans += Calc(a, b);
    cout << ans << '\n';
  }
  return 0;
}
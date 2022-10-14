/**
 *    author:  milos
 *    created: 30.03.2021 20:28:36       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int s;
    cin >> s;
    int ans = 0;
    auto Get = [&](int n) {
      int m = 1;
      while (m < n) {
        m *= 10;
      }
      while (m > n) {
        m /= 10;
      }
      return m;
    };
    while (s > 0) {
      int big = Get(s); 
      ans += big;
      s -= big;
      s += (big / 10);
    }
    cout << ans << '\n';
  }
  return 0;
}
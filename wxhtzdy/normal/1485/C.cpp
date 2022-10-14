/**
 *    author:  milos
 *    created: 12.02.2021 20:46:24       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    long long ans = 0;
    for (int i = 1; i <= sqrt(x); i++) {
      ans += max(0, min(x / i - 1, y) - i);
    }
    cout << ans << '\n';
  }
  return 0;
}
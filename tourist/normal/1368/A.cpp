/**
 *    author:  tourist
 *    created: 18.06.2020 17:19:09       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    while (max(a, b) <= n) {
      if (a > b) {
        b += a;
      } else {
        a += b;
      }
      ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}
/**
 *    author:  wxhtzdy
 *    created: 01.08.2022 16:34:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, h, m;
    cin >> n >> h >> m;
    int ans = 12345;
    int t = h * 60 + m;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      int c = x * 60 + y;
      if (t <= c) {
        ans = min(ans, c - t);
      } else {
        ans = min(ans, 24 * 60 + c - t);
      }
    }
    cout << ans / 60 << " " << ans % 60 << '\n';
  }                                                                    
  return 0;
}
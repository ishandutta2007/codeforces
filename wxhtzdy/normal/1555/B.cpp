/**
 *    author:  milos
 *    created: 01.08.2021 07:43:11       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int szx = x2 - x1, szy = y2 - y1;
    int ans = 1e9;
    if (szx + w <= W) {
      ans = min(ans, max(0, w - x1));
      ans = min(ans, max(0, x2 - (W - w)));
    }
    if (szy + h <= H) {
      ans = min(ans, max(0, h - y1));
      ans = min(ans, max(0, y2 - (H - h)));
    }
    cout << fixed << setprecision(6) << (ans == 1e9 ? -1 : ans) << '\n'; 
  }
  return 0;
}
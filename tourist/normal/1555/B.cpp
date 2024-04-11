/**
 *    author:  tourist
 *    created: 30.07.2021 17:36:46       
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
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int w, h;
    cin >> w >> h;
    const int inf = (int) 1e9;
    int ans = inf;
    if (w + (xb - xa) <= W) {
      ans = min(ans, max(0, w - xa));
      ans = min(ans, max(0, xb - (W - w)));
    }
    if (h + (yb - ya) <= H) {
      ans = min(ans, max(0, h - ya));
      ans = min(ans, max(0, yb - (H - h)));
    }
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}
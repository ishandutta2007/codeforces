/**
 *    author:  tourist
 *    created: 29.04.2018 16:14:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  vector<int> l(cl);
  for (int i = 0; i < cl; i++) {
    cin >> l[i];
  }
  sort(l.begin(), l.end());
  vector<int> e(ce);
  for (int i = 0; i < ce; i++) {
    cin >> e[i];
  }
  sort(e.begin(), e.end());
  int tt;
  cin >> tt;
  while (tt--) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int ans = (int) 2e9;
    if (xa == xb) {
      ans = abs(ya - yb);
    } else {
      int pos_l = (int) (lower_bound(l.begin(), l.end(), ya) - l.begin());
      if (pos_l < cl) {
        ans = min(ans, abs(xa - xb) + abs(ya - l[pos_l]) + abs(yb - l[pos_l]));
      }
      if (pos_l > 0) {
        ans = min(ans, abs(xa - xb) + abs(ya - l[pos_l - 1]) + abs(yb - l[pos_l - 1]));
      }
      int pos_e = (int) (lower_bound(e.begin(), e.end(), ya) - e.begin());
      if (pos_e < ce) {
        ans = min(ans, (abs(xa - xb) + v - 1) / v + abs(ya - e[pos_e]) + abs(yb - e[pos_e]));
      }
      if (pos_e > 0) {
        ans = min(ans, (abs(xa - xb) + v - 1) / v + abs(ya - e[pos_e - 1]) + abs(yb - e[pos_e - 1]));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
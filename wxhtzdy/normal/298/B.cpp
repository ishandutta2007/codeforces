/**
 *    author:  milos
 *    created: 24.03.2021 10:50:00       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;
  string s;
  cin >> s;
  map<char, int> cnt;
  if (sx >= ex) {
    cnt['W'] = sx - ex;
  }
  if (sx < ex) {
    cnt['E'] = ex - sx;
  }
  if (sy >= ey) {
    cnt['S'] = sy - ey;
  }
  if (sy < ey) {
    cnt['N'] = ey - sy;
  }
  if (sx == ex && sy == ey) {
    cout << 0 << '\n';
    return 0;
  }
  map<char, int> curr;
  for (int i = 0; i < t; i++) {
    curr[s[i]]++;
    bool ok = true;
    for (char c : {'W', 'E', 'S', 'N'}) {
      if (cnt[c] > curr[c]) {
        ok = false;
      }
    }
    if (ok) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
/**
 *  author: milos
 *  created: 04.01.2021 23:38:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h;
  cin >> w >> h;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  for (int i = h; i >= 0; i--) {
    w += i;
    if (i == y1) {
      w -= x1;  
    }
    if (i == y2) {
      w -= x2;
    }
    w = max(w, 0);
  }
  cout << w << '\n';
  return 0;
}
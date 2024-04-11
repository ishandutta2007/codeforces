/**
 *    author:  tourist
 *    created: 10.03.2021 15:52:38       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
      cin >> s[i];
    }
    int shift = (h % 3 == 1 ? 0 : 1);
    for (int r = shift; r < h; r += 3) {
      for (int c = 0; c < w; c++) {
        s[r][c] = 'X';
      }
      if (r + 3 < h) {
        bool found = false;
        for (int c = 0; c < w; c++) {
          if (s[r + 1][c] == 'X' || s[r + 2][c] == 'X') {
            s[r + 1][c] = s[r + 2][c] = 'X';
            found = true;
            break;
          }
        }
        if (!found) {
          s[r + 1][0] = s[r + 2][0] = 'X';
        }
      }
    }
    for (int i = 0; i < h; i++) {
      cout << s[i] << '\n';
    }
  }
  return 0;
}
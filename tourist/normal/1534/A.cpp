/**
 *    author:  tourist
 *    created: 13.06.2021 18:34:21       
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
    bool found = false;
    for (int r = 0; r < 2; r++) {
      bool ok = true;
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          char c = ((i + j + r) % 2 == 0 ? 'R' : 'W');
          if (s[i][j] == c) ok = false;
        }
      }
      if (ok) {
        cout << "YES" << '\n';
        for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
            char c = ((i + j + r + 1) % 2 == 0 ? 'R' : 'W');
            cout << c;
          }
          cout << '\n';
        }
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
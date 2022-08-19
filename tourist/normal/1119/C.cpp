/**
 *    author:  tourist
 *    created: 06.04.2019 12:39:42       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<int>> b(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> b[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] != b[i][j]) {
        if (i == h - 1 || j == w - 1) {
          cout << "No" << '\n';
          return 0;
        }
        a[i][j] ^= 1;
        a[i + 1][j] ^= 1;
        a[i][j + 1] ^= 1;
        a[i + 1][j + 1] ^= 1;
      }
    }
  }
  cout << "Yes" << '\n';
  return 0;
}
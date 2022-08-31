/**
 *    author:  tourist
 *    created: 17.12.2019 18:13:52       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  vector<vector<int>> a(r, vector<int>(c, 0));
  if (r >= 2 && c >= 2) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        a[i][j] = (i + 1) * (r + j + 1);
      }
    }
  } else {
    if (r >= 2 || c >= 2) {
      for (int i = 0; i < max(r, c); i++) {
        (r >= 2 ? a[i][0] : a[0][i]) = i + 2;
      }
    } else {
      cout << 0 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
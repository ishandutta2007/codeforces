/**
 *    author:  tourist
 *    created: 25.08.2019 17:40:46       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  int x = 0;
  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < n; j += 4) {
      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
          a[i + ii][j + jj] = x++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) cout << " ";
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
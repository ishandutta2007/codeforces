/**
 *    author:  tourist
 *    created: 03.04.2021 17:58:21       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  for (int it = 0; it < n * n; it++) {
    int a;
    cin >> a;
    int b = -1;
    int x = -1;
    int y = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] == 0 && (i + j) % 2 == 0 && a != 1) {
          b = 1;
          x = i;
          y = j;
          break;
        }
      }
      if (b != -1) {
        break;
      }
    }
    if (b == -1) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (g[i][j] == 0 && (i + j) % 2 == 1 && a != 2) {
            b = 2;
            x = i;
            y = j;
            break;
          }
        }
        if (b != -1) {
          break;
        }
      }
      if (b == -1) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (g[i][j] == 0) {
              b = 3;
              x = i;
              y = j;
              break;
            }
          }
          if (b != -1) {
            break;
          }
        }
      }
    }
    cout << b << " " << x + 1 << " " << y + 1 << endl;
    g[x][y] = b;
  }
  return 0;
}
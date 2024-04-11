/**
 *    author:  milos
 *    created: 08.04.2021 21:22:51       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> col(n, vector<int>(n));
  for (int rep = 0; rep < n * n; rep++) {
    int a;
    cin >> a;
    int b = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (col[i][j] == 0 && (i + j) % 2 == 0 && a != 1) {
          b = 1, x = i, y = j;
          break;
        }
      }
      if (b != 0) {
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (col[i][j] == 0 && (i + j) % 2 == 1 && a != 2 && b == 0) {
          b = 2, x = i, y = j;
          break;
        }
      }
      if (b != 0) {
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (col[i][j] == 0 && a != 3 && b == 0) {
          b = 3, x = i, y = j;
          break;  
        }
      }
      if (b != 0) {
        break;
      }
    }
    assert(b != 0); 
    col[x][y] = b;
    cout << b << " " << x + 1 << " " << y + 1 << endl;
  }
  return 0;
}
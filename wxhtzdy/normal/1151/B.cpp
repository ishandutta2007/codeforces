/**
 *    author:  milos
 *    created: 25.02.2021 09:46:49       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int xr = 0;
  for (int i = 0; i < n; i++) {
    xr ^= a[i][0];
  }
  if (xr > 0) {
    cout << "TAK" << '\n';
    for (int i = 0; i < n; i++) {
      cout << 1 << " ";  
    }
    return 0;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (a[i][j] != a[i][0]) {
          cout << "TAK" << '\n';
          for (int k = 0; k < n; k++) {
            if (k != i) {
              cout << 1 << " ";
            } else {
              cout << j + 1 << " ";
            }
          }
          return 0;  
        }
      }
    }
    cout << "NIE" << '\n';
  }
  return 0;
}
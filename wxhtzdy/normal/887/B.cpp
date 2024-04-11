/**
 *  author: milos
 *  created: 14.01.2021 22:20:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(6));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i < 100; i++) {
    bool ok = false;
    if (i < 10) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 6; k++) {
          if (a[j][k] == i) {
            ok = true;
          }
        }
      }
    } else {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 6; k++) {
          if (a[j][k] == i / 10) {
            for (int l = 0; l < n; l++) {
              if (l == j) {
                continue;
              }
              for (int t = 0; t < 6; t++) {
                if (a[l][t] == i % 10) {
                  ok = true;                
              }
              }
            }
          }
        }
      }
    }
    if (!ok) {
      cout << i - 1 << '\n';
      break;
    }
  }
  return 0;
}
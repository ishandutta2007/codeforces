/**
 *    author:  tourist
 *    created: 25.07.2021 17:36:33       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    int id = 0;
    for (int i = 1; i < n; i++) {
      int cc = 0;
      for (int j = 0; j < 5; j++) {
        cc += (a[i][j] < a[id][j]);
      }
      if (cc >= 3) {
        id = i;
      }
    }
    for (int i = 0; i < n; i++) {
      int cc = 0;
      for (int j = 0; j < 5; j++) {
        cc += (a[i][j] < a[id][j]);
      }
      if (cc >= 3) {
        id = -2;
        break;
      }
    }
    cout << id + 1 << '\n';
  }
  return 0;
}
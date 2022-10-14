/**
 *    author:  milos
 *    created: 01.08.2021 15:22:43       
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
    auto Win = [&](int i, int j) {
      int cnt = 0;
      for (int x = 0; x < 5; x++) {
        cnt += (a[i][x] < a[j][x]);
      }
      return cnt >= 3;
    };
    int id = 0;
    for (int i = 1; i < n; i++) {
      if (Win(i, id)) {
        id = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != id && !Win(id, i)) {
        id = -2;
        break;  
      }
    }
    cout << id + 1 << '\n';
  }
  return 0;
}
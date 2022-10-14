/**
 *    author:  milos
 *    created: 12.02.2021 20:24:27       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 720720;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }              
  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        ans[i][j] = N;
      } else {
        ans[i][j] = N + a[i][j] * a[i][j] * a[i][j] * a[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
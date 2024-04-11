/**
 *    author:  wxhtzdy
 *    created: 16.10.2022 12:46:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }             
  vector<int> ans(n);
  ans[0] = sqrt(a[0][1] * 1LL * a[0][2] / a[1][2]);
  for (int i = 1; i < n; i++) {
    ans[i] = a[0][i] / ans[0];
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}
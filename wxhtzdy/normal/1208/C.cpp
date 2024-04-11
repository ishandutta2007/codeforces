/**
 *  author: milos
 *  created: 26.12.2020 02:14:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> ans(n, vector<int>(n));
  int cnt = 0;
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      ans[i][j] = cnt * 4;
      ans[i][j + n / 2] = cnt * 4 + 1;
      ans[i + n / 2][j] = cnt * 4 + 2;
      ans[i + n / 2][j + n / 2] = cnt * 4 + 3;
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
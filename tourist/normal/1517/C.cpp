/**
 *    author:  tourist
 *    created: 23.04.2021 17:42:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<vector<int>> a(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    int x = i;
    int y = i;
    a[x][y] = p[i];
    for (int it = 1; it < p[i]; it++) {
      if (y > 0 && a[x][y - 1] == -1) {
        --y;
      } else {
        ++x;
      }
      assert(a[x][y] == -1);
      a[x][y] = p[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
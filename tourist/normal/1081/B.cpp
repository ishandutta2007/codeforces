/**
 *    author:  tourist
 *    created: 16.12.2018 17:45:40       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int same = n - x;
    a[same].push_back(i);
  }
  vector<int> res(n, -1);
  int cc = 0;
  for (int i = 1; i <= n; i++) {
    int sz = (int) a[i].size();
    if (sz % i != 0) {
      cout << "Impossible" << '\n';
      return 0;
    }
    for (int j = 0; j < sz; j += i) {
      for (int k = 0; k < i; k++) {
        res[a[i][j + k]] = cc;
      }
      ++cc;
    }
  }
  cout << "Possible" << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i] + 1;
  }
  cout << '\n';
  return 0;
}
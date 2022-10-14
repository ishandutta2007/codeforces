/**
 *  author: milos
 *  created: 14.01.2021 22:30:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 24;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto Ok = [&](vector<int> p) {
    for (int i = 1; i < 7; i++) {
      for (int j = 4 * i - 3; j <= 4 * i; j++) {
        if (p[j - 1] != p[4 * i - 1]) {
          return false;
        }
      }
    }
    return true;
  };
  vector<vector<int>> all = {
  {0, 2, 4, 6, 8, 10, 23, 21},
  {1, 3, 5, 7, 9, 11, 22, 20},
  {12, 13, 4, 5, 16, 17, 20, 21},
  {10, 11, 19, 17, 1, 0, 12, 14},
  {8, 9, 18, 16, 3, 2, 13, 15},
  {14, 15, 6, 7, 18, 19, 22, 23},
  };                                        
  for (int rep = 0; rep < 6; rep++) {
    auto b = a;
    for (int i = 0; i < (int) all[rep].size(); i++) {
      b[all[rep][i]] = a[all[rep][(i + 2) % 8]];
    }
    if (Ok(b)) {
      cout << "YES" << '\n';
      return 0;
    }
    for (int i = 0; i < (int) all[rep].size(); i++) {
      b[all[rep][i]] = a[all[rep][(i + 6) % 8]];
    }
    if (Ok(b)) {
      cout << "YES" << '\n';
      return 0;  
    }
  }
  cout << "NO" << '\n';
  return 0;
}
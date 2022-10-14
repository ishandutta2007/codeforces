/**
 *  author: milos
 *  created: 27.12.2020 18:34:18
**/
#include <bits/stdc++.h>

using namespace std;
           
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  auto Solve = [&](int x, int y) {
    cout << (x + sx - 2) % n + 1 << " " << (y + sy - 2) % m + 1 << '\n';  
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i % 2 == 0) {
        Solve(i + 1, j + 1);
      } else {
        Solve(i + 1, m - j);
      }
    }
  }
  return 0;
}
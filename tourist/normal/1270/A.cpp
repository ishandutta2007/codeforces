/**
 *    author:  tourist
 *    created: 29.12.2019 17:05:11       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int foo, n, m;
    cin >> foo >> n >> m;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      int z;
      cin >> z;
      x = max(x, z);
    }
    for (int i = 0; i < m; i++) {
      int z;
      cin >> z;
      y = max(y, z);
    }
    cout << (x > y ? "YES" : "NO") << '\n';
  }
  return 0;
}
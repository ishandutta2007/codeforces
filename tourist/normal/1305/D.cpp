/**
 *    author:  tourist
 *    created: 03.03.2020 18:02:21       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> alive(n, 1);
  while (true) {
    vector<int> deg(n);
    vector<int> leaves;
    for (int i = 0; i < n; i++) {
      if (!alive[i]) {
        continue;
      }
      for (int j : g[i]) {
        if (alive[j]) {
          ++deg[i];
        }
      }
      if (deg[i] == 1) {
        leaves.push_back(i);
      }
    }
    if (leaves.size() < 2) {
      vector<int> any;
      for (int i = 0; i < n; i++) {
        if (alive[i]) {
          any.push_back(i);
        }
      }
      assert(any.size() == 1);
      cout << "! " << any[0] + 1 << endl;
      return 0;
    }
    cout << "? " << leaves[0] + 1 << " " << leaves[1] + 1 << endl;
    int z;
    cin >> z;
    if (z == leaves[0] + 1 || z == leaves[1] + 1) {
      cout << "! " << z << endl;
      return 0;
    }
    alive[leaves[0]] = alive[leaves[1]] = 0;
  }
  return 0;
}
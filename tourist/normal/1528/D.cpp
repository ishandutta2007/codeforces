/**
 *    author:  tourist
 *    created: 24.05.2021 17:52:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int inf = (int) 2e9;
  vector<vector<int>> g(n, vector<int>(n, inf));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a][b] = min(g[a][b], c);
  }
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < 2 * n; x++) {
      int j = x % n;
      int k = (x + 1) % n;
      g[i][k] = min(g[i][k], g[i][j] + 1);
    }
  }
  for (int start = 0; start < n; start++) {
    vector<int> d(n, inf);
    d[start] = 0;
    vector<bool> alive(n, true);
    for (int it = 0; it < n; it++) {
      int id = -1;
      for (int i = 0; i < n; i++) {
        if (alive[i] && (id == -1 || d[i] < d[id])) {
          id = i;
        }
      }
      alive[id] = false;
      int r = d[id] % n;
      for (int i = 0; i < n; i++) {
        d[r] = min(d[r], d[id] + g[id][i]);
        r += 1;
        if (r == n) {
          r = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << d[i];
    }
    cout << '\n';
  }
  return 0;
}
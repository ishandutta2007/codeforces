#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int N = 50;
  vector<vector<bool>> e(N, vector<bool>(N, false));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    if (u < N && v < N) {
      e[u][v] = e[v][u] = true;
    }
  }
  n = min(n, N);
  for (int i1 = 0; i1 < n; i1++) {
    for (int i2 = i1 + 1; i2 < n; i2++) {
      for (int i3 = i2 + 1; i3 < n; i3++) {
        for (int i4 = i3 + 1; i4 < n; i4++) {
          for (int i5 = i4 + 1; i5 < n; i5++) {
            bool x = false, y = false;
            for (int u : {i1, i2, i3, i4, i5}) {
              for (int v : {i1, i2, i3, i4, i5}) {
                if (u == v) {
                  continue;
                }
                if (e[u][v]) {
                  x = true;
                } else {
                  y = true;
                }
              }
            }
            if (x != y) {
              cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << " " << i4 + 1 << " " << i5 + 1 << '\n';
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}
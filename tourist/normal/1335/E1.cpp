/**
 *    author:  tourist
 *    created: 13.04.2020 17:43:36       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    const int M = 200;
    vector<vector<int>> pref(M, vector<int>(n + 1));
    vector<vector<int>> at(M);
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < n; j++) {
        pref[i][j + 1] = pref[i][j] + (a[j] == i);
        if (a[j] == i) {
          at[i].push_back(j);
        }
      }
    }
    int ans = 0;
    for (int x = 0; x < M; x++) {
      int u = pref[x][n];
      ans = max(ans, u);
      for (int c = 1; 2 * c <= u; c++) {
        int from = at[x][c - 1];
        int to = at[x][u - c];
        for (int y = 0; y < M; y++) {
          if (x != y) {
            ans = max(ans, 2 * c + pref[y][to] - pref[y][from]);
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
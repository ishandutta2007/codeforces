/**
 *    author:  tourist
 *    created: 06.12.2020 17:49:33       
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
    vector<string> s(n);
    vector<int> x(3);
    vector<int> o(3);
    int k = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'X') {
          x[(i + j) % 3] += 1;
          k += 1;
        }
        if (s[i][j] == 'O') {
          o[(i + j) % 3] += 1;
          k += 1;
        }
      }
    }
    bool found = false;
    for (int u = 0; u < 3; u++) {
      for (int v = 0; v < 3; v++) {
        if (u != v && x[u] + o[v] <= k / 3 && !found) {
          found = true;
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              if ((i + j) % 3 == u && s[i][j] == 'X') {
                s[i][j] = 'O';
              }
              if ((i + j) % 3 == v && s[i][j] == 'O') {
                s[i][j] = 'X';
              }
            }
            cout << s[i] << '\n';
          }
        }
      }
    }
    assert(found);
  }
  return 0;
}
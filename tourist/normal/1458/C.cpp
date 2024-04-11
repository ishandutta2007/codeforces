/**
 *    author:  tourist
 *    created: 19.12.2020 13:42:39       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(n * n, vector<int>(3));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int v;
        cin >> v;
        --v;
        p[i * n + j][0] = i;
        p[i * n + j][1] = j;
        p[i * n + j][2] = v;
      }
    }
    string s;
    cin >> s;
    vector<int> order(3);
    iota(order.begin(), order.end(), 0);
    vector<int> shift(3, 0);
    for (char c : s) {
      if (c == 'R') {
        shift[1] = (shift[1] + 1) % n;
      }
      if (c == 'L') {
        shift[1] = (shift[1] + n - 1) % n;
      }
      if (c == 'D') {
        shift[0] = (shift[0] + 1) % n;
      }
      if (c == 'U') {
        shift[0] = (shift[0] + n - 1) % n;
      }
      if (c == 'I') {
        swap(order[1], order[2]);
        swap(shift[1], shift[2]);
      }
      if (c == 'C') {
        swap(order[0], order[2]);
        swap(shift[0], shift[2]);
      }
    }
    vector<vector<int>> a(n, vector<int>(n, -1));
    vector<int> z(3);
    for (int i = 0; i < n * n; i++) {
      for (int j = 0; j < 3; j++) {
        z[j] = (p[i][order[j]] + shift[j]) % n;
      }
      a[z[0]][z[1]] = z[2];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) {
          cout << " ";
        }
        assert(a[i][j] != -1);
        cout << a[i][j] + 1;
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}
/**
 *    author:  tourist
 *    created: 25.01.2021 18:10:03       
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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
      if (a[i][0] == '1') {
        for (int j = 0; j < n; j++) {
          a[i][j] ^= '0' ^ '1';
        }
      }
      if (b[i][0] == '1') {
        for (int j = 0; j < n; j++) {
          b[i][j] ^= '0' ^ '1';
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (a[0][j] == '1') {
        for (int i = 0; i < n; i++) {
          a[i][j] ^= '0' ^ '1';
        }
      }
      if (b[0][j] == '1') {
        for (int i = 0; i < n; i++) {
          b[i][j] ^= '0' ^ '1';
        }
      }
    }
    cout << (a == b ? "YES" : "NO") << '\n';
  }
  return 0;
}
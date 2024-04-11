/**
 *    author:  milos
 *    created: 26.01.2021 01:05:26       
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
    for (int i = 0; i < n; i++) {
      cin >> s[i];  
    }
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = (int) (s[i][j] - '0');
      }
    }
    vector<string> t(n);
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        b[i][j] = (int) (t[i][j] - '0');
      }
    }
    auto Can = [&](vector<vector<int>> x, vector<vector<int>> y) {
      for (int i = 0; i < n; i++) {
        if (x[0][i] != y[0][i]) {
          for (int j = 0; j < n; j++) {
            x[j][i] = 1 - x[j][i];
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if ((x[i][0] ^ y[i][0]) != (x[i][j] ^ y[i][j])) {
            return false;
          }
        }
      }
      return true;
    };
    bool ok = false;
    for (int j = 0; j < 2; j++) {
      if (Can(a, b)) {
        ok = true;  
      }
      for (int i = 0; i < n; i++) {
        a[0][i] ^= 1;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
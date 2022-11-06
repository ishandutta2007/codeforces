#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  const string kChar = "RGBYW";
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    a[i] = find(kChar.begin(), kChar.end(), s[0]) - kChar.begin();
    b[i] = s[1] - '1';
  }
  int res = 10;
  for (int s = 0; s < (1 << 5); ++s) {
    for (int t = 0; t < (1 << 5); ++t) {
      vector<vector<bool>> adj(n, vector<bool>(n));
      for (int i = 0; i < 5; ++i) {
        if (s >> i & 1) {
          for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
              if (a[j] == i && a[k] != i) {
                adj[j][k] = true;
                adj[k][j] = true;
              }
            }
          }
        }
        if (t >> i & 1) {
          for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
              if (b[j] == i && b[k] != i) {
                adj[j][k] = true;
                adj[k][j] = true;
              }
            }
          }
        }
      }
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          ok &= a[i] == a[j] && b[i] == b[j] || adj[i][j];
        }
      }
      if (ok) {
        res = min(res, __builtin_popcount(s) + __builtin_popcount(t));
      }
    }
  }
  cout << res << "\n";
}
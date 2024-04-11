/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 14:59:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      --a[i][j];
    }
  }                         
  vector<int> L(n * n, n);             
  vector<int> R(n * n, -1);             
  vector<int> U(n * n, n);
  vector<int> D(n * n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      L[a[i][j]] = min(L[a[i][j]], j);
      R[a[i][j]] = max(R[a[i][j]], j);
      U[a[i][j]] = min(U[a[i][j]], i);
      D[a[i][j]] = max(D[a[i][j]], i);
    }
  }           
  for (int i = 0; i < n * n; i++) {
    if (L[i] != n) {
      k -= 1;
    }
  }        
  if (k >= 0) {
    cout << k << '\n';
    return 0;
  }
  k = -k;
  for (int d = 1; d <= n; d++) {
    vector<vector<int>> b(n + 1, vector<int>(n + 1));
    for (int c = 0; c < n * n; c++) {
      if (L[c] == n) {
        continue;
      }
      int xa = max(0, D[c] - d + 1);
      int xb = U[c] + 1;
      int ya = max(0, R[c] - d + 1);
      int yb = L[c] + 1;
      if (xa >= xb || ya >= yb) {
        continue;
      }
      b[xa][ya] += 1;
      b[xa][yb] -= 1;
      b[xb][ya] -= 1;
      b[xb][yb] += 1;
    }
    for (int i = 0; i <= n - d; i++) {
      for (int j = 0; j <= n - d; j++) {
        if (i > 0) {
          b[i][j] += b[i - 1][j];
        }
        if (j > 0) {
          b[i][j] += b[i][j - 1];
        }
        if (i > 0 && j > 0) {
          b[i][j] -= b[i - 1][j - 1];
        }
        if (b[i][j] == k || b[i][j] == k + 1) {
          cout << 1 << '\n';
          return 0;
        }
      }
    }
  }
  cout << 2 << '\n';
  return 0;
}
/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 18:03:14
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
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      --c[i];
    }
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      a[c[i]][i % 2] = max(a[c[i]][i % 2], a[c[i]][1 - (i % 2)] + 1);
    }
    for (int i = 0; i < n; i++) {
      cout << max(a[i][0], a[i][1]) << " \n"[i == n - 1];
    }
  }                                                                    
  return 0;
}
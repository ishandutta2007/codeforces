/**
 *    author:  wxhtzdy
 *    created: 23.08.2022 12:35:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  int ans = 0;
  int mn = 1e9;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (a[i] < a[j] && b[i] < b[j] && c[i] < c[j]) {
        ok = false;
      }
    }
    if (ok) {              
      if (mn > d[i]) {
        mn = d[i];
        ans = i;
      }
    }
  }
  cout << ans + 1 << '\n';     
  return 0;
}
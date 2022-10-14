/**
 *    author:  milos
 *    created: 24.03.2021 11:02:21       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  if (n > m || a[0] > b[0]) {
    cout << "YES" << '\n';
    return 0;
  }
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      ok = true;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}
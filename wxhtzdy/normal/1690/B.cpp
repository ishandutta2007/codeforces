/**
 *    author:  wxhtzdy
 *    created: 07.06.2022 20:43:10
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
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    bool ok = true;   
    for (int i = 0; i < n; i++) {
      ok &= (a[i] >= b[i]);
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    int ops = 1e9;
    for (int i = 0; i < n; i++) {
      if (b[i] != 0) {
        ops = min(ops, a[i] - b[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      a[i] = max(0, a[i] - ops);
      ok &= (a[i] == b[i]);
    }   
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}
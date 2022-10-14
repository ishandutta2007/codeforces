/**
 *    author:  wxhtzdy
 *    created: 16.07.2022 18:13:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] + x > a[i + n]) {
        ok = false;
      }
    }           
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}
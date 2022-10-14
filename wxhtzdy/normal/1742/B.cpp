/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 16:36:11
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
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 1; i < n; i++) {
      ok = (ok & (a[i] > a[i - 1]));
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}
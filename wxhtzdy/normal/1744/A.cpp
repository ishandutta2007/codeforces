/**
 *    author:  wxhtzdy
 *    created: 16.10.2022 16:34:26
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
    string s;
    cin >> s;
    vector<char> f(55, ' ');
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (f[a[i]] != ' ') {
        if (f[a[i]] != s[i]) {
          ok = false;
        }
      } else {
        f[a[i]] = s[i];
      }
    } 
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}
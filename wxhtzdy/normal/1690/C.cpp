/**
 *    author:  wxhtzdy
 *    created: 07.06.2022 21:13:01
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
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
      cin >> f[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cout << f[i] - max(mx, s[i]) << " ";
      mx = max(mx, f[i]);
    }
    cout << '\n';
  }                                                                    
  return 0;
}
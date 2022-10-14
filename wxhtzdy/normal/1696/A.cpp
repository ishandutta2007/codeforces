/**
 *    author:  wxhtzdy
 *    created: 26.06.2022 18:24:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      mx = max(mx, a[i] | z);
    }
    cout << mx << '\n';
  }   
  return 0;
}
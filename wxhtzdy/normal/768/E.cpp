/**
 *    author:  wxhtzdy
 *    created: 31.08.2022 14:27:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  vector<int> a(1, 0);
  for (int i = 1; i <= 20; i++) {
    for (int j = 0; j <= i; j++) {
      a.push_back(i);
    }
  }
  int n;
  cin >> n;
  int xr = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    xr ^= a[x];
  }
  cout << (xr == 0 ? "YES" : "NO") << '\n';                                                         
  return 0;
}
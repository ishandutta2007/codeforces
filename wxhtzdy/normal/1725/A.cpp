/**
 *    author:  wxhtzdy
 *    created: 05.09.2022 17:44:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  if (min(n, m) == 1) {
    cout << max(n, m) - 1 << '\n';
  } else {
    cout << n * 1LL * (m - 1) << '\n';
  }                                                                  
  return 0;
}
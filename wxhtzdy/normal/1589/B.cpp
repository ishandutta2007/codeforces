/**
 *    author:  wxhtzdy
 *    created: 19.07.2022 06:57:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    cout << (n * m + 2) / 3 << '\n';
  }                                                                    
  return 0;
}
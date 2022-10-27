/**
 *    author:  wxhtzdy
 *    created: 18.10.2022 18:05:40
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
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }
    n = 10 - n;
    cout << 6 * n * (n - 1) / 2 << '\n';
  }                                                                    
  return 0;
}
/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 17:38:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    if (x == 0 && y == 0) {
      cout << -1 << '\n';
      continue;
    }
    if (x < y) {
      swap(x, y);
    }       
    if (y != 0) {
      cout << -1 << '\n';
      continue;
    }
    if ((n - 1) % x != 0) {
      cout << -1 << '\n';
      continue;
    }
    int idx = 2;
    int wins = x;
    for (int i = 0; i < n - 1; i++) {
      if (wins == 0) {
        wins = x;
        idx += x;
      }  
      cout << idx << " ";
      wins -= 1;      
    }
    cout << '\n';
  }                                                                    
  return 0;
}
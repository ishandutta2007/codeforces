/**
 *    author:  wxhtzdy
 *    created: 04.08.2022 16:34:34
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
    if (n == 1) {
      cout << 2 << '\n';
    } else {
      cout << (n + 2) / 3 << '\n';
    }
  }                                                                    
  return 0;
}
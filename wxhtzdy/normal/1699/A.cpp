/**
 *    author:  wxhtzdy
 *    created: 04.07.2022 16:34:33
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
    if (n % 2 == 0) {
      cout << n / 2 << " " << 0 << " " << 0 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }                                                                    
  return 0;
}
/**
 *    author:  wxhtzdy
 *    created: 18.10.2022 18:07:39
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
    cout << 1 << " ";
    for (int i = n; i >= 2; i--) {
      cout << i << " ";
    }
    cout << '\n';
  }                                                                    
  return 0;
}
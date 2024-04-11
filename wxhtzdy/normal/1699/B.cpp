/**
 *    author:  wxhtzdy
 *    created: 08.07.2022 10:53:57
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
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i % 4 == 0 || i % 4 == 3) {
          if (j % 4 == 0 || j % 4 == 3) {
            cout << 0;
          } else {
            cout << 1;
          }
        } else {
          if (j % 4 == 0 || j % 4 == 3) {
            cout << 1;
          } else {
            cout << 0;
          }
        }
        cout << " ";
      }
      cout << '\n';
    }
  }                                                                    
  return 0;
}
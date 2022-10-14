/**
 *    author:  wxhtzdy
 *    created: 07.09.2022 18:43:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    --r; --c;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ".X"[((i + j) % k) == ((r + c) % k)];
      }
      cout << '\n';
    }
  }                                                                    
  return 0;
}
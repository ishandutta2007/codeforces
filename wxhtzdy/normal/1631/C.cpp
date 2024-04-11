/**
 *    author:  wxhtzdy
 *    created: 30.01.2022 15:48:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (k == n - 1 && n == 4) {
      cout << -1 << '\n';
    } else {            
      if (k == 0) {
        for (int i = 0; i < n / 2; i++) {
          cout << i << " " << n - i - 1 << '\n';
        }
        continue;
      } if (k < n - 1) {
        cout << k << " " << n - 1 << '\n';
        cout << 0 << " " << n - k - 1 << '\n';
        vector<int> v;
        for (int i = 1; i + 1 < n; i++) {
          if (i != k && i != n - k - 1) {
            v.push_back(i);
          }
        }
        for (int i = 0; i < (int) v.size() / 2; i++) {
          cout << v[i] << " " << v[v.size() - i - 1] << '\n';
        }
      } else {
        cout << 0 << " " << 2 << '\n';
        cout << n - 1 << " " << n - 2 << '\n';
        cout << n - 3 << " " << 1 << '\n';
        for (int i = 3; i < n - 3 && i < n - i - 1; i++) {
          cout << i << " " << n - i - 1 << '\n'; 
        }
      }
    }
  }                                                                    
  return 0;
}
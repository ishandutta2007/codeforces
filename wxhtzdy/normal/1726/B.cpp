/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 20:57:40
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
    if (n % 2 == 1) {
      if (n > m) {
        cout << "No" << '\n';
        continue;        
      }
      vector<int> a(n, 1);
      a[n - 1] += (m - n);
      cout << "Yes" << '\n';
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
      }
    } else {             
      if (n > m || n % 2 != m % 2) {
        cout << "No" << '\n';
        continue;
      }
      vector<int> a(n, 1);     
      int x = m - n;
      a[n - 1] += x / 2;
      a[n - 2] += x / 2;
      cout << "Yes" << '\n';
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];         
      }
    }
  }                                                                    
  return 0;
}
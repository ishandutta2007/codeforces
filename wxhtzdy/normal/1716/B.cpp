/**
 *    author:  wxhtzdy
 *    created: 04.08.2022 16:37:05
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
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    cout << n << '\n';
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
      }
      if (j == n - 1) {
        break;
      }                  
      if (j == 0) {
        swap(a[0], a[1]);
      } else {          
        for (int i = 0; i < n; i++) {
          if (a[i] == i + 1) { 
            for (int k = 0; k < i; k++) {
              if (a[k] != i + 1 && a[i] != k + 1) {
                swap(a[i], a[k]);
                break;
              }
            }
            break;
          }
        }
      }
    }
  }                                                                    
  return 0;
}
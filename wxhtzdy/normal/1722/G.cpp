/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 15:46:05
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
    if (n % 4 == 0) {
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          cout << i / 2 << " ";
        } else {
          cout << i / 2 + (1 << 25) << " ";
        }
      }
      cout << '\n';
      continue;
    }
    if (n % 4 == 1) {
      cout << "2 0 4 5 3 ";
      int pr = 6;
      for (int i = 5; i < n; i++) {
        if (i % 2 == 1) {
          cout << pr << " ";          
        } else {
          cout << pr + (1 << 25) << " ";
          pr++;
        }
      }
      cout << '\n';
      continue;
    }
    if (n % 4 == 2) {
      cout << "4 1 2 12 3 8 ";
      int pr = 13;
      for (int i = 6; i < n; i++) {
        if (i % 2 == 0) {
          cout << pr << " ";          
        } else {
          cout << pr + (1 << 25) << " ";
          pr++;
        }
      }
      cout << '\n';
      continue;
    }
    if (n % 4 == 3) {
      cout << "2 1 3 ";
      int pr = 4;
      for (int i = 3; i < n; i++) {
        if (i % 2 == 1) {
          cout << pr << " ";          
        } else {
          cout << pr + (1 << 25) << " ";
          pr++;
        }
      }
      cout << '\n';
      continue;  
    }
  }                                                                    
  return 0;
}
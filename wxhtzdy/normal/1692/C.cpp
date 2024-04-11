/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 17:00:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n = 8;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }      
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        bool ok = true;
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < n; y++) {
            if (abs(x - i) == abs(y - j) && s[x][y] == '.') {
              ok = false;
            }
            if (abs(x - i) != abs(y - j) && s[x][y] == '#') {
              ok = false;
            }
          }
        }
        {
          for (int x = 0; x < n; x++) {
            int ni = i + x;
            int nj = j + x;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && s[ni][nj] == '.') {
              ok = false;
            }
          }
        }
        {
          for (int x = 0; x < n; x++) {
            int ni = i - x;
            int nj = j + x;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && s[ni][nj] == '.') {
              ok = false;
            }
          }
        }
        {
          for (int x = 0; x < n; x++) {
            int ni = i + x;
            int nj = j - x;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && s[ni][nj] == '.') {
              ok = false;
            }
          }
        }
        {
          for (int x = 0; x < n; x++) {
            int ni = i - x;
            int nj = j - x;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && s[ni][nj] == '.') {
              ok = false;
            }
          }
        }
        if (ok) {
          cout << i + 1 << " " << j + 1 << '\n';
        }
      }
    }
  }                                                                    
  return 0;
}
/**
 *    author:  milos
 *    created: 24.03.2021 10:40:45       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      for (int j = i; j < n; j++) {
        if (s[j] != 'R') {
          cout << j << " " << j + 1 << '\n';
          return 0;
        }
      }
      return 0;
    }
    if (s[i] == 'L') {
      cout << i + 1 << " " << i << '\n';
      return 0;
    }
  }
  return 0;
}
/**
 *    author:  wxhtzdy
 *    created: 18.06.2022 20:34:14
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
    string s;
    cin >> s;
    if (s == string(n, '1')) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << (i == j ? 'X' : '=');
        }
        cout << '\n';
      }
    } else {
      if (count(s.begin(), s.end(), '2') <= 2) { 
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      vector<int> ids;
      for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
          ids.push_back(i);
        }
      }
      vector<int> f(n);
      for (int i = 0; i < (int) ids.size(); i++) {
        f[ids[i]] = ids[(i + 1) % (int) ids.size()];
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            cout << 'X';
          } else if (s[i] == '2' && s[j] == '2' && f[i] == j) {
            cout << '+';
          } else if (s[i] == '2' && s[j] == '2' && f[j] == i) {
            cout << '-';
          } else {
            cout << '=';
          }
        }   
        cout << '\n';
      }
    }
  }                                                                    
  return 0;
}
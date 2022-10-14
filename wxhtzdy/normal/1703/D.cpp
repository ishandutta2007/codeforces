/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 15:22:22
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
    map<string, bool> have;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      have[s[i]] = true;
    }
    for (int i = 0; i < n; i++) {
      bool ok = false;
      for (int j = 0; j < (int) s[i].size() - 1; j++) {
        string x = "";
        string y = "";
        for (int k = 0; k <= j; k++) {
          x += s[i][k];
        }
        for (int k = j + 1; k < (int) s[i].size(); k++) {
          y += s[i][k]; 
        }
        if (have[x] && have[y]) {
          ok = true;
        }
      }
      cout << ok;
    }
    cout << '\n';
  }                                                                    
  return 0;
}
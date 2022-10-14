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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }               
    for (int j = 0; j < m; j++) {
      vector<int> ss;
      ss.push_back(n);
      for (int i = n - 1; i >= 0; i--) {
        if (s[i][j] == 'o') {
          ss.push_back(i);
        }
      }
      ss.push_back(-1);
      for (int x = 0; x + 1 < ss.size(); x++) {
        int R = ss[x];
        int L = ss[x + 1];
        int cnt = 0; 
        for (int i = L + 1; i < R; i++) {
          if (s[i][j] == '*') {
            cnt += 1;
          }
          s[i][j] = '.';
        }
        R -= 1;            
        while (cnt--) {
          s[R][j] = '*';
          R -= 1;
        }
      }    
    }
    for (int i = 0; i < n; i++) {
      cout << s[i] << '\n';
    }
    cout << '\n';
  }                                                                    
  return 0;
}
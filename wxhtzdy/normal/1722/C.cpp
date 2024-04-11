/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 15:32:47
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
    map<string, int> mp;                       
    vector<vector<string>> s(3, vector<string>(n));
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        cin >> s[i][j];
        mp[s[i][j]] += 1;
      }
    }
    vector<int> score(4);
    score[1] = 3;
    score[2] = 1;
    for (int i = 0; i < 3; i++) {
      int res = 0;
      for (int j = 0; j < n; j++) {
        res += score[mp[s[i][j]]];
      }
      cout << res << " ";
    }
    cout << '\n';
  }                                                                    
  return 0;
}
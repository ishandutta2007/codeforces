/**
 *  author: milos
 *  created: 06.01.2021 21:13:33
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int a = (int) (s[0][1] - '0') + (int) (s[1][0] - '0');
    int b = (int) (s[n - 1][n - 2] - '0') + (int) (s[n - 2][n - 1] - '0');
    vector<pair<int, int>> ans;
    if (a == 0) {
      if (s[n - 1][n - 2] == '0') {
        ans.push_back({n, n - 1});
      }
      if (s[n - 2][n - 1] == '0') {
        ans.push_back({n - 1, n});  
      }
    } else {
      if (a == 1) {
        if (b == 0) {
          if (s[0][1] == '0') {
            ans.push_back({1, 2});
          } else {
            ans.push_back({2, 1});
          }
        } else {
          if (b == 1) {
            if (s[0][1] == '0') {
              ans.push_back({1, 2});
            } else {
              ans.push_back({2, 1});
            }
            if (s[n - 1][n - 2] == '1') {
              ans.push_back({n, n - 1});
            } else {
              ans.push_back({n - 1, n});
            }   
          } else {
            if (s[0][1] == '1') {
              ans.push_back({1, 2});
            } else {
              ans.push_back({2, 1});
            }  
          }
        }
      } else {          
        if (s[n - 1][n - 2] == '1') {
          ans.push_back({n, n - 1});
        }
        if (s[n - 2][n - 1] == '1') {
          ans.push_back({n - 1, n});  
        }
      }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << '\n';
    }
  }
  return 0;
}
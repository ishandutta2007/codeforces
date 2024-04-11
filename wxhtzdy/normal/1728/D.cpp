/**
 *    author:  wxhtzdy
 *    created: 08.09.2022 16:48:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();    
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, -1)));
    function<int(int, int, int)> Solve = [&](int l, int r, int f) {
      if (l > r) {
        return 0;
      }
      if (dp[l][r][f] != -1) {
        return dp[l][r][f];
      }     
      int idx = ((r - l) % 2 == 1 ? 0 : 1);
      if (idx == 0) {
        int L = Solve(l + 1, r, 0);
        int R = Solve(l, r - 1, 1);
        if (L == 1 || R == 1) {
          dp[l][r][f] = 1;
        } else if (L == 2 && R == 2) {
          dp[l][r][f] = 2;
        } else {
          dp[l][r][f] = 0;
        }
        return dp[l][r][f];
      } else {
        char he = (f == 0 ? s[l - 1] : s[r + 1]);
        int L = Solve(l + 1, r, 2);
        int R = Solve(l, r - 1, 2);
        if (L == 2 || R == 2) {
          dp[l][r][f] = 1;   
        } else if (L == 1 && R == 1) {
          dp[l][r][f] = 1;           
        } else {
          int win = 1;
          int can_draw = 0;
          if (L == 0) {
            if (he < s[l]) {
              win = 2;
            } else if (he == s[l]) {
              can_draw = 1;
            }
          }
          if (R == 0) {
            if (he < s[r]) {
              win = 2;
            } else if (he == s[r]) {
              can_draw = 1;
            }
          }
          if (win == 1 && can_draw == 1) {
            win = 0;
          }       
          dp[l][r][f] = win;
        }
        return dp[l][r][f];    
      }  
    };
    int ans = Solve(0, n - 1, 2);
    cout << (ans == 0 ? "Draw" : (ans == 1 ? "Alice" : "Bob")) << '\n';
  }                                                                    
  return 0;
}
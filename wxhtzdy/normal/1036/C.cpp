/**
 *    author:  wxhtzdy
 *    created: 28.08.2022 12:59:26
**/
#include <bits/stdc++.h>

using namespace std;

// digit dp just for practice

int dp[20][2][4];

int Solve(long long n) {
  if (n == 0) {
    return 0;
  }
  vector<int> d;          
  while (n > 0) {
    d.push_back(n % 10);
    n /= 10;       
  }
  d.push_back(0);
  reverse(d.begin(), d.end());
  memset(dp, 0, sizeof dp);
  int k = (int) d.size();
  dp[0][1][0] = 1;
  for (int i = 1; i < k; i++) {
    for (int s = 0; s < 2; s++) {
      for (int x = 0; x <= 3; x++) {
        for (int dig = 0; dig < 10; dig++) {
          if (s == 1 && dig > d[i]) {
            continue;
          }
          if (x == 3 && dig > 0) {
            continue;
          }
          int new_s = (s & (dig == d[i]));
          int new_x = (x + (dig > 0));
          dp[i][new_s][new_x] += dp[i - 1][s][x];  
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= 3; j++) {
      ans += dp[k - 1][i][j];
    }    
  }           
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    long long L, R;
    cin >> L >> R;
    cout << Solve(R) - Solve(L - 1) << '\n';
  }                                                                    
  return 0;
}
/**
 *    author:  milos
 *    created: 25.08.2021 05:50:28       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1);
  dp[n] = 1;            
  long long sum = 0;
  for (int i = n; i > 0; i--) {
    dp[i] = (dp[i] + sum) % m;
    for (int j = sqrt(i); j >= 1; j--) {
      if (i != j) {
        int l = i / (j + 1);
        int r = i / j;
        dp[j] = (dp[j] + dp[i] * max(0, r - l) % m) % m;
        if (i / j != j && i / j != i) {
          dp[i / j] = (dp[i / j] + dp[i]) % m;
        }
      }
    }
    sum = (sum + dp[i]) % m;
  }
  cout << dp[1] << '\n';
  return 0;
}
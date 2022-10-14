/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 18:31:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  long long k;
  cin >> k;
  string s;
  cin >> s;
  vector<vector<long long>> dp(n, vector<long long>(n + 1));
  const long long inf = 1e12;
  for (int i = 0; i < n; i++) {
    dp[i][1] = 1;
  } 
  vector<int> lst(26, -1);
  for (int j = 2; j <= n; j++) {     
    fill(lst.begin(), lst.end(), -1);
    for (int i = 0; i < n; i++) {
      dp[i][1] = 1;
      for (int c = 0; c < 26; c++) {
        if (lst[c] != -1) {
          dp[i][j] += dp[lst[c]][j - 1];
          dp[i][j] = min(dp[i][j], inf); 
        }
      }
      lst[(int) (s[i] - 'a')] = i;
    }
  }
  fill(lst.begin(), lst.end(), -1);
  for (int i = 0; i < n; i++) {
    lst[(int) (s[i] - 'a')] = i;
  }
  long long ans = 0;
  for (int l = n; l >= 1; l--) {
    long long sum = 0;
    for (int i = 0; i < 26; i++) {
      if (lst[i] != -1) {
        sum += dp[lst[i]][l];
        sum = min(sum, inf); 
      }
    }
    sum = min(sum, k);
    ans += sum * (n - l);
    k -= sum;
  }
  if (k > 0) {
    ans += n;
    k -= 1;
  }
  if (k > 0) {
    ans = -1;
  }
  cout << ans << '\n';                                              
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 155;

int dp[N][N * N];

int n, k, s, A[N];

int calc(int x) {
  return (x == 1) ? 1 : -1;
}

int main() {
  cin >> n >> k >> s;
  for(int i = 1; i <= n; ++ i) {
    cin >> A[i];
  }
  int All = 0;
  memset(dp, 127, sizeof(dp));
  dp[0][0] = 0;
  for(int i = 1; i <= n; ++ i) {
    if(i <= k)
      for(int j = min(i, k); j >= 0; -- j) {
      for(int l = min(All, s); l >= 0; -- l) if(dp[j][l] <= 1e9){
	if(j || i <= k)
	  dp[j + calc(i <= k)][l + abs(i - k)] = min(dp[j + calc(i <= k)][l + abs(i - k)], dp[j][l] + calc(i > k) * A[i]);
      }
    }
    else {
      for(int j = 0; j <= min(i, k); ++ j) {
        for(int l = min(All, s); l >= 0; -- l) if(dp[j][l] <= 1e9){
	    if(j || i <= k)
	      dp[j + calc(i <= k)][l + abs(i - k)] = min(dp[j + calc(i <= k)][l + abs(i - k)], dp[j][l] + calc(i > k) * A[i]);
	  }
      }
    }
    All += abs(i - k);
  }
  int ans = 0;
  for(int i = 0; i <= min(s, All); ++ i) ans = min(ans, dp[0][i]);
  for(int i = 1; i <= k; ++ i) ans += A[i];
  cout << ans << endl;
}
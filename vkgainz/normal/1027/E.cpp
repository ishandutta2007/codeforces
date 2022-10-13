#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 1e6+5;
typedef long long ll;

int main() {
  int n, k; cin >> n >> k;
  ll dp[n+1][n+1][2];
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=n;j++) {
      dp[i][j][0] = 0, dp[i][j][1] = 0;
    }
  }
  int t[501];
  ll mod = 998244353;
  t[0] = 1;
  for(int i=1;i<=500;i++)
    t[i] = t[i-1]*2%mod;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      if(j>=i) {
        dp[i][j][0] = t[i-1];
        dp[i][j][1] = t[i-1];
      }
      else {
        for(int k=1;k<=j;k++) {
          dp[i][j][0]+=dp[i-k][j][1];
          dp[i][j][1]+=dp[i-k][j][0];
        }
      }
      dp[i][j][0]%=mod;
      dp[i][j][1]%=mod;
    }
  }
  ll ans = 0;
  for(int w=1;w<=min(k-1, n);w++) {
    int maxH =(k-1)/w;
    ans+=dp[n][min(maxH,n)][0]*1LL*(dp[n][w][0]-dp[n][w-1][0])%mod;
    ans%=mod;
  }
  cout << (ans*2%mod+mod)%mod;
}
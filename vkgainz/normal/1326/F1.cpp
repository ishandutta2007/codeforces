#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n; cin >> n;
  string in[n];
  for(int i=0;i<n;i++) {
    cin >> in[i];
  }
  vector<ll> dp[1<<n][n];
  for(int msk=1;msk<1<<n;msk++) {
    if(__builtin_popcount(msk) > 14) continue;
    int cnt = __builtin_popcount(msk);
    for(int j=0;j<n;j++) {
      if(msk&(1<<j)) {
        dp[msk][j].resize(1<<(cnt-1));
        if(cnt == 1) {
          continue;
        }
        else if(cnt == 2) {
          for(int x=0;x<n;x++) {
            if(msk&(1<<x) && x != j) {
              ++dp[msk][j][in[j][x] - '0'];
            }
          }
        }
        else {
          for(int x=0;x<n;x++) {
            if(msk&(1<<x) && x!=j) {
              for(int nmsk=0;nmsk<(1<<(cnt-1));nmsk++) {
                if(nmsk%2 == in[j][x] - '0') {
                  dp[msk][j][nmsk] += dp[msk^(1<<j)][x][nmsk/2];
                }
              }
            }
          }
        }
      }
    }
  }
  if(n <= 14) {
    for(int msk=0;msk<1<<(n-1);msk++) {
      ll ans = 0LL;
      for(int j=0;j<n;j++) {
        ans += dp[(1<<n)-1][j][msk];
      }
      cout << ans << "\n";
    }
  }
  else {
    //merge
    vector<ll> ans(1<<(n-1));
    for(int leftmsk=0;leftmsk<1<<n;leftmsk++) {
      if(__builtin_popcount(leftmsk) != 7) continue;
      int rightmsk = (1<<n) - 1 - leftmsk;
      for(int msk=0;msk<1<<6;msk++) {
        for(int other=0;other<1<<(n-8);other++) {
        }
      }
    }
  }
}
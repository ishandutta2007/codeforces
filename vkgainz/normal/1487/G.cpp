#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 5e5+5;
using cd = complex<double>;
const double PI = acos(-1);

int main() {
  int n; cin >> n;
  vector<int> c(26);
  for(auto &a : c) cin >> a;
  ll MOD = 998244353;
  ll g0 = 1LL;
  for(int i=0;i<n;i+=2) {
    if(i == 0)
      g0 *= 26;
    else
      g0 *= 25;
    g0 %= MOD;
  }
  for(int i=1;i<n;i+=2) {
    if(i == 1)
      g0 *= 26;
    else
      g0 *= 25;
    g0 %= MOD;
  }
  //check below bounds...
  vector<vector<array<ll, 2>>> dp((n+3)/2, vector<array<ll, 2>>((n+7)/4));
  dp[1][1][1] = 1LL, dp[1][0][0] = 25LL;
  int left = (n+1)/2, right = n - left;
  for(int i=2; i <= (n+1)/2; i++) {
    for(int j=0; j <= (n+3)/4; j++) {
      //fill i spots with j occurrences of a certain letter
      //dp[i][j][0] ==> place another letter on ith spot, otherwise place given letter
      if(j)
        dp[i][j][1] += dp[i-1][j-1][0];

      dp[i][j][0] += 25*1LL*dp[i-1][j][1];
      dp[i][j][0] += 24*1LL*dp[i-1][j][0]; //check this?

      dp[i][j][1] %= MOD, dp[i][j][0] %= MOD;
    }
  }
  vector<ll> dpL((n+7)/4), dpR((n+7)/4);
  for(int j=0;j<=(n+3)/4;j++) {
    dpL[j] = dp[left][j][0] + dp[left][j][1];
    dpR[j] = dp[right][j][0] + dp[right][j][1];
    dpL[j] %= MOD, dpR[j] %= MOD;
  }
  vector<ll> dpComb((n+6)/2);
  for(int x=0;x<=(n+3)/4;x++) {
    for(int y=0;y<=(n+3)/4;y++) {
      dpComb[x+y] += dpL[x]*1LL*dpR[y];
      dpComb[x+y] %= MOD; //maybe move outside
    }
  }
  for(int i=0;i<(n+4)/2;i++) {
    if(i) dpComb[i] += dpComb[i-1];
    dpComb[i] %= MOD;
  }
  //dpComb[j] = j occurences of certain letter
  //dpComb[j] = sum of dp[left][x]*dp[right][j-x] from x=0 to x=j
  
  vector<vector<vector<array<ll, 3>>>> dpBoth((n+3)/2, vector<vector<array<ll, 3>>>((n+7)/4, vector<array<ll, 3>>((n+7)/4)));
  //0 = another letter, 1 = first letter, 2 = second letter
  dpBoth[1][0][0][0] = 24LL, dpBoth[1][1][0][1] = 1LL, dpBoth[1][0][1][2] = 1LL;
  for(int i=2;i<=(n+1)/2;i++) {
    for(int j=0;j<=(n+3)/4;j++) {
      for(int k=0;k<=(n+3)/4;k++) {
        dpBoth[i][j][k][0] += 23*1LL*dpBoth[i-1][j][k][0] + 24*1LL*dpBoth[i-1][j][k][1] + 24*1LL*dpBoth[i-1][j][k][2];
        if(j)
          dpBoth[i][j][k][1] += dpBoth[i-1][j-1][k][2] + dpBoth[i-1][j-1][k][0];
        if(k)
          dpBoth[i][j][k][2] += dpBoth[i-1][j][k-1][0] + dpBoth[i-1][j][k-1][1];
        dpBoth[i][j][k][0] %= MOD, dpBoth[i][j][k][1] %= MOD, dpBoth[i][j][k][2] %= MOD;
      }
    }
  }
  vector<vector<ll>> dpLBoth((n+7)/4, vector<ll>((n+7)/4)), dpRBoth((n+7)/4, vector<ll>((n+7)/4));
  for(int x=0;x<=(n+3)/4;x++) {
    for(int y=0;y<=(n+3)/4;y++) {
      dpLBoth[x][y] = dpBoth[left][x][y][0] + dpBoth[left][x][y][1] + dpBoth[left][x][y][2];
      dpRBoth[x][y] = dpBoth[right][x][y][0] + dpBoth[right][x][y][1] + dpBoth[right][x][y][2];
      dpLBoth[x][y] %= MOD, dpRBoth[x][y] %= MOD;
    }
  }
  vector<vector<ll>> dpCombBoth((n+6)/2, vector<ll>((n+6)/2));
  for(int i=0;i<=(n+3)/4;i++) {
    for(int j=0;j<=(n+3)/4;j++) {
      for(int k=0;k<=(n+3)/4;k++) {
        for(int l=0;l<=(n+3)/4;l++) {
          dpCombBoth[i+j][k+l] += dpLBoth[i][k]*1LL*dpRBoth[j][l];
          dpCombBoth[i+j][k+l] %= MOD;
        }
      }
    }
  }
  for(int i=0;i<(n+6)/2;i++) {
    for(int j=0;j<(n+6)/2;j++) {
      if(i) dpCombBoth[i][j] += dpCombBoth[i-1][j];
      if(j) dpCombBoth[i][j] += dpCombBoth[i][j-1];
      if(i && j) dpCombBoth[i][j] -= dpCombBoth[i-1][j-1];
      dpCombBoth[i][j] %= MOD;
    }
  }
  ll g1 = 0LL;
  for(int i=0;i<26;i++) {
    if(c[i] <= (n+2)/2) {
      g1 += dpComb[(n+2)/2];
      g1 -= dpComb[c[i]];
    }
    g1 %= MOD;
  }
  ll g2 = 0LL;
  for(int i=0;i<26;i++) {
    for(int j=i+1;j<26;j++) {
      if(c[i] <= (n+2)/2 && c[j] <= (n+2)/2) {
        g2 += dpCombBoth[(n+2)/2][(n+2)/2];
        g2 += dpCombBoth[c[i]][c[j]];
        g2 -= dpCombBoth[(n+2)/2][c[j]];
        g2 -= dpCombBoth[c[i]][(n+2)/2];
      }
      g2 %= MOD;
    }
  }
  ll ans = g0 - g1 + g2 % MOD;
  ans %= MOD;
  if(ans < 0) ans += MOD;
  cout << ans << "\n";
  //dpCombBoth[j][k] = j occurrences of certain letter, k occurrences of another
}
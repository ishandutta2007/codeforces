#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 1e5+5;
int dp[101][101][101];
int main() {
  int t; cin >> t;
  while(t--) {
    int b, p, f; cin >> b >> p >> f;
    int h, c; cin >> h >> c;
  for(int i=0;i<=100;i++) {
    for(int j=0;j<=100;j++) {
      for(int k=0;k<=100;k++) {
        dp[i][j][k] = 0;
        if(i >= 2 && j >= 1)
          dp[i][j][k] = max(dp[i][j][k], dp[i-2][j-1][k] + h);
        if(i >= 2 && k >= 1)
          dp[i][j][k] = max(dp[i][j][k], dp[i-2][j][k-1] + c);
      }
    }
  }
  cout << dp[b][p][f] << "\n";
  }
}
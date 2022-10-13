#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;
const int MX = 2e5+5;
int dp[401][401];
int main() {
  int T; cin >> T;
  while(T--) {
    string s, t; cin >> s >> t;
    for(int i=0;i<=t.length();i++) {
      for(int j=0;j<=t.length();j++) {
        dp[i][j] = -1e9;
      }
    }
    for(int k=0;k<=t.length();k++) {
      dp[0][k] = max(k-1, 0);
    }
    for(int i=1;i<=s.length();i++) {
      int next[401][401];
      for(int j=0;j<=t.length();j++) for(int k=0;k<=t.length();k++) next[j][k] = dp[j][k];
      for(int j=0;j<=t.length();j++) {
        for(int k=j+1;k<=t.length();k++) {
          //add to second
          if(dp[j][k]>=0) {
            int add = dp[j][k]+1;
            if(s[i-1]==t[add-1]) next[j][k] = max(next[j][k], add);
          }
          //add to first
          if(j>=1 && dp[j-1][k]>=0) {
            if(s[i-1]==t[j-1]) next[j][k] = max(next[j][k], dp[j-1][k]);
          }
        }
      }
      for(int j=0;j<=t.length();j++) for(int k=0;k<=t.length();k++) dp[j][k] = next[j][k];
    }
    bool work = false;
    for(int a=0;a<=t.length();a++) {
      if(dp[a][a+1]==t.length()) work = true;
    }
    if(work) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}
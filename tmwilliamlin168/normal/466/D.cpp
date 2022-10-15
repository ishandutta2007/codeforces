#include<iostream>
using namespace std;
 
#define M 1000000007

long long dp[2010][2010];
int a[2010];
inline void add(long long &a, long long b) {
   a += b;
   a %= M;
}
int main() {
     ios_base::sync_with_stdio(0);
     int n,h;
     cin >> n >> h;
     
     for (int i = 1; i <= n ;i ++)
         cin >> a[i];
 
     dp[1][0] = (a[1] == h || a[1] + 1 == h?1:0);
     dp[1][1] = (a[1] + 1 == h?1:0);
     
     for (int i = 2;i <= n + 1; i ++)
      for (int open = max(0,h - a[i]- 1); open <= min(h - a[i],i) ; open ++){
          if (a[i] + open == h){
             add(dp[i][open] , dp[i - 1][open]);
             if (open > 0)
                add(dp[i][open] , dp[i - 1][open - 1]);
          }
          if (open + a[i] + 1 == h){
               add(dp[i][open] , dp[i - 1][open + 1] * (open + 1));
               add(dp[i][open] , dp[i - 1][open]);
               add(dp[i][open] , dp[i - 1][open] * open);
          }
      }
     cout << dp[n][0];
}
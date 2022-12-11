#include <iostream>
 
 using namespace std;

const int INF = 1e9;
 
 int main() {
     int n, b;
     cin >> n >> b;
     int a[n + 1];
     for (int i = 1; i <= n; i++) cin >> a[i];
     bool ok[n + 1];
     int cnt = 0;
     for (int i = 1; i <= n; i++) {
         if (a[i] % 2 == 0) cnt++;
         if (cnt * 2 == i) ok[i] = 1;
         else ok[i] = 0;
     }
     int dp[n + 1][b + 1];
     //dp[0][b] = 0;
     for (int i = 0; i <= b; i++) dp[0][i] = 0;
     for (int i = 1; i <= n; i++) {
         if (!ok[i]) continue;
         //cout << i << endl;
         for (int j = 0; j <= b; j++) {
             dp[i][j] = 0;
             for (int last = i - 1; last >= 1; last--) {
                 if (ok[last] && abs(a[last] - a[last + 1]) <= j) {
                     //cout << i << ' ' << j << ' ' << last << ' ' << dp[endl;
                     dp[i][j] = max(dp[i][j], dp[last][j - abs(a[last] - a[last + 1])] + 1);
                 }
             }
         }
     }
     cout << dp[n][b] << endl;
     return 0;
 }
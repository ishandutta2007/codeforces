#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int dp[101][2];

signed main(){
    int n, k, d, mn1, mn2;
    cin >> n >> k >> d;
    mn1 = min(d - 1, n);
    mn2 = min(n, k);
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
        for (int j = 1; j <= k; j++){
            if (i - j < 0){
                break;
            }
            if (j < d){
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
            else{
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
        }
    }
    cout << dp[n][1];
}
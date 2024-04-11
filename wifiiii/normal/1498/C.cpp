#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
ll dp[1005][1005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        dp[0][0] = dp[0][1] = 1;
        for(int j = 1; j <= k; ++j) {
            for(int i = 0; i <= n; ++i) {
                if(j == 1 || i == 0) dp[i][j] = 1;
                else dp[i][j] = (dp[i-1][j] + dp[n-i][j-1]) % mod;
            }
        }
        cout << dp[n][k] << endl;
    }
}
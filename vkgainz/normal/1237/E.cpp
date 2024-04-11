#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll dp[1000001][2];
int main(){
    int n; cin >> n;
    dp[1][1] = 1;
    dp[1][0] = 0;
    dp[2][1] = 0;
    dp[2][0] = 1;
    // 0 = even, 1 = odd;
    for(int i=3;i<=1000000;i++){
        if(i%2){
            int x = (i-1)/2;
            if((x+1)%2) dp[i][1] = dp[x][0]*dp[x][0]%mod;
            else dp[i][0] = dp[x][1]*dp[x][0]%mod;
        }
        else{
            int x = i/2;
            dp[i][1] = dp[x-1][0]*dp[x][0]%mod;
            if(x%2){
                dp[i][0] = dp[x][1]*dp[x-1][0]%mod;
            }
            else{
                dp[i][0] = dp[x-1][1]*dp[x][0]%mod;
            }
        }
    }
    ll ans = dp[n][0]+dp[n][1];
    ans%=mod;
    if(ans<0) ans+=mod;
    cout << ans << endl;

}
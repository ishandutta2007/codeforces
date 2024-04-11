#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int dp[MAXN][2]; // 0, 1

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int last=0;
        for (int i=1;i<=n;++i){
            int curr; cin >> curr;
            if (last==curr) dp[i][0]=dp[i-1][0];
            else if (last+1==curr) dp[i][0]=dp[i-1][0]+1;
            else dp[i][0]=max(dp[i-1][1]+1,dp[i-1][0]+1);
            if (last==curr) dp[i][1]=max(dp[i-1][0]+1,dp[i-1][1]);
            else dp[i][1]=max(dp[i-1][0]+1,dp[i-1][1]+1);
            last=curr;
        }
        cout << max(dp[n][0],dp[n][1]) << '\n';
    }
}
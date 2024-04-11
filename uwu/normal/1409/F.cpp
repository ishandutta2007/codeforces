#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=201;

int dp[MAXN][MAXN][MAXN]; // pos, #a, moves

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    string s; cin >> s; s=" "+s;
    char a,b; cin >> a >> b;
    if (a==b){
        int cnt=0;
        for (char x:s) if (x==a) cnt++;
        cnt=min(n,cnt+k);
        cout << (cnt*(cnt-1))/2 << '\n';
        return 0;
    }
    ms(dp,-0x3f);
    dp[0][0][0]=0;
    for (int i=1;i<=n;++i){
        for (int j=0;j<=i;++j){
            for (int k=0;k<=i;++k){
                if (s[i]==a&&j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]);
                if (k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]);
                if (s[i]==b) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+j);
                if (k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+j);
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
            }
        }
    }
    int ans=0;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=k;++j){
            //cout << i << " " << j << " -> " << dp[n][i][j] << '\n';
            ans=max(ans,dp[n][i][j]);
        }
    }
    cout << ans << '\n';
}
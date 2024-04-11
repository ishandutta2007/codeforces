#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5001;

int dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    a=" "+a, b=" "+b;
    int ans=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i]==b[j]) dp[i][j]=max(0,dp[i-1][j-1]+2);
            else dp[i][j]=max({dp[i-1][j]-1,dp[i][j-1]-1,0});
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans << '\n';
}
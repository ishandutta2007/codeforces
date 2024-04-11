#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=5007;
const int INF=1e16;
int dp[maxn][maxn];
int n,m,l[maxn],s[maxn],c[maxn];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>l[i];
    for (int i=1;i<=n;++i) cin>>s[i];
    for (int i=1;i<=n+m;++i) cin>>c[i];
    reverse(l+1,l+n+1), reverse(s+1,s+n+1);
    for (int i=0;i<=n+m;++i){
        for (int j=1;j<=n;++j){
            dp[i][j]=-INF;
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=n;j>-1;--j){
            dp[l[i]][j+1]=max(dp[l[i]][j+1],dp[l[i]][j]-s[i]+c[l[i]]);
        }
        for (int k=1;k<=20&&k+l[i]<=n+m;++k){
            for (int j=0;j<=(n>>(k-1));++j){
                dp[l[i]+k][j/2]=max(dp[l[i]+k][j/2],dp[l[i]+k-1][j]+c[l[i]+k]*(j/2));
            }
        }
        for (int j=1;j<=n+m;++j){
            dp[j][0]=max(dp[j][0],dp[j-1][0]);
        }
    }
    cout<<dp[n+m][0]<<endl;
    return 0;
}
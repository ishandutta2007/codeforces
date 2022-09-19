#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
const int maxn=255;
int dp[maxn][maxn][maxn];
int pr[maxn];
int32_t main()
{
    for(int i=0;i<maxn;++i) for(int j=0;j<maxn;++j) for(int k=0;k<maxn;++k) dp[i][j][k]=1e9;
    int n,s;cin>>n>>s;
    int a[n];for(int i=0;i<n;++i) {cin>>a[i];pr[i+1]=pr[i]+a[i];}
    dp[0][0][s]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=s;++j)
        {
            for(int k=0;k<=s;++k)
            {
            if(dp[i][j][k]==1e9) continue;
            for(int t=0;t<=k && t+j<=s;++t)
            {
                dp[i+1][j+t][t]=min(dp[i+1][j+t][t],dp[i][j][k]+abs(j+t-pr[i+1]));
            }
            }
        }
    }
    int ans=1e9;
    for(int k=0;k<=s;++k)
    {
        ans=min(ans,dp[n][s][k]);
    }
    cout<<ans;
    return 0;
}
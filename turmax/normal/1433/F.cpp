#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
    int dp[n][m+1][m+1][k];
    for(int i=0;i<n;++i) for(int j=0;j<=m;++j) for(int l=0;l<=m;++l) for(int o=0;o<k;++o) dp[i][j][l][o]=(-1e18);
    for(int i=0;i<n;++i) {dp[i][0][0][0]=0;}
    int z[n+1][k];
    for(int i=0;i<=n;++i) for(int j=0;j<k;++j) z[i][j]=(-1e18);
    z[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            for(int cn=0;cn<=j;++cn)
            {
            for(int l=0;l<k;++l)
            {
                dp[i][j+1][cn+1][(l+a[i][j])%k]=max(dp[i][j][cn][l]+a[i][j],dp[i][j+1][cn+1][(l+a[i][j])%k]);
                dp[i][j+1][cn][l]=max(dp[i][j][cn][l],dp[i][j+1][cn][l]);
            }
            }
        }
        for(int cn=0;cn<=(m/2);++cn)
        {
            for(int l1=0;l1<k;++l1)
            {
                for(int l2=0;l2<k;++l2)
                {
                    z[i+1][(l1+l2)%k]=max(z[i+1][(l1+l2)%k],z[i][l1]+dp[i][m][cn][l2]);
                }
            }
        }
    }
    cout<<z[n][0];
    return 0;
}
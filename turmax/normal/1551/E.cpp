#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int dp[n+1][n+1];
        for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) dp[i][j]=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+((a[i]+j-1)==i));
            }
        }
        int ans=(-1);
        for(int i=0;i<=n;++i) if(dp[n][i]>=k) {ans=i;break;}
        cout<<ans<<'\n';
    }
    return 0;
}
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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int ans=0;
        int dp[n+1][2];
        dp[n][0]=0;dp[n][1]=0;
        for(int i=(n-1);i>=0;i--)
        {
            dp[i][0]=1e18;
            dp[i][0]=min(dp[i][0],dp[i+1][1]+a[i]);
            if(i!=(n-1))
            {
                dp[i][0]=min(dp[i][0],dp[i+2][1]+a[i]+a[i+1]);
            }
            if(i!=(n-1))
            dp[i][1]=min(dp[i+1][0],dp[i+2][0]);
            else
            dp[i][1]=dp[i+1][0];
        }
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
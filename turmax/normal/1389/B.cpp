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
    int n,k,z;
    cin>>n>>k>>z;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int dp[k+1][z+1];
    for(int i=0;i<=z;++i) dp[0][i]=0;
    for(int i=1;i<=k;++i)
    {
        for(int j=0;j<=z;++j)
        {
            dp[i][j]=0;
            int curr=(k-i-2*j);
            if(curr<0 || curr>=n) {dp[i][j]=(-1e18);continue;}
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a[curr+1]);
            if(curr!=0 && j!=z)
            dp[i][j]=max(dp[i][j],dp[i-1][j+1]+a[curr-1]);
        }
    }
    int ans=0;
    for(int i=0;i<=z;++i)
    {
        ans=max(ans,dp[k][i]);
    }
    cout<<ans+a[0]<<endl;
    }
    return 0;
}
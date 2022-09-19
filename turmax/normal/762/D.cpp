#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[3][n];
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    int dp[3][n];
    dp[0][0]=a[0][0];
    dp[1][0]=a[0][0]+a[1][0];
    dp[2][0]=a[0][0]+a[1][0]+a[2][0];
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            dp[j][i]=dp[j][i-1]+a[j][i];
        }
        int u0=dp[0][i];int u1=dp[1][i];int u2=dp[2][i];
        dp[1][i]=max(u1,u0+a[1][i]);
        dp[2][i]=max(dp[2][i],dp[1][i]+a[2][i]);
        int z1=max(u1,u2+a[1][i]);
        dp[1][i]=max(dp[1][i],u2+a[1][i]);
        dp[0][i]=max(dp[0][i],z1+a[0][i]);
        int sum=a[0][i-1]+a[1][i-1]+a[2][i-1]+a[0][i]+a[1][i]+a[2][i];
        if(i>=2) {
        dp[0][i]=max(dp[0][i],dp[0][i-2]+sum);
        dp[2][i]=max(dp[2][i],dp[0][i-2]+sum);
        dp[0][i]=max(dp[0][i],dp[2][i-2]+sum);
        dp[2][i]=max(dp[2][i],dp[2][i-2]+sum);
        }
        else
        {
        dp[0][i]=max(dp[0][i],sum);
        dp[2][i]=max(dp[2][i],sum);
        dp[0][i]=max(dp[0][i],sum);
        dp[2][i]=max(dp[2][i],sum);
        }
    }
    //cout<<dp[2][2]<<" dp[2][2] "<<endl;
    cout<<dp[2][n-1];
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int r,n;
    cin>>r>>n;
    int tm[n+1];int x[n+1];int y[n+1];
    tm[0]=0;x[0]=1;y[0]=1;
    for(int i=1;i<=n;++i)
    {
        cin>>tm[i]>>x[i]>>y[i];
    }
    int dp[n+1];dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        dp[i]=(-1e18);
        for(int j=(i-1);j>=max(0LL,i-4*r);--j)
        {
            if((dp[j]+1)>dp[i] && (tm[i]-tm[j])>=abs(x[i]-x[j])+abs(y[i]-y[j]))
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    cout<<*max_element(dp,dp+n+1);
    return 0;
}
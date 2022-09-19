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
        sort(a,a+n);
        int dp[n+1][2*n+1];
        for(int i=0;i<=(2*n);++i)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;++i)
        {
            dp[i][i-1]=1e18;
            for(int j=i;j<=(2*n);++j)
            {
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[i-1]-j));
            }
        }
        cout<<dp[n][2*n]<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e3+5;
int dp[maxn+1][maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i)
    {
        dp[n][i]=0;
    }
    for(int i=(n-1);i>=0;i--)
    {
        for(int j=0;j<=n;++j)
        {
            int curr=a[i]-j;
            if(curr<=0)
            {
                dp[i][j]=dp[i+1][min(a[i],n)];
                continue;
            }
            dp[i][j]=min(dp[i+1][j]+1,dp[i+1][min(a[i],n)]+curr);
        }
    }
    cout<<dp[0][0];
    return 0;
}
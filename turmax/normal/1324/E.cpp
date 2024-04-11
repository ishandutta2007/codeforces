#include <bits/stdc++.h>

using namespace std;
#define int long long
bool val(int l,int x,int r)
{
    return x>=l && x<=r;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int dp[n+1][h];
    for(int i=0;i<h;++i)
    {
        dp[n][i]=0;
    }
    for(int i=(n-1);i>=0;--i)
    {
        for(int j=0;j<h;++j)
        {
            int ans=0;
            if(val(l,(j+a[i])%h,r))
            {
                ans=max(ans,dp[i+1][(j+a[i])%h]+1);
            }
            else
            {
                ans=max(ans,dp[i+1][(j+a[i])%h]);
            }
            if(val(l,(j+a[i]-1)%h,r))
            {
                ans=max(ans,dp[i+1][(j+a[i]-1)%h]+1);
            }
            else
            {
                ans=max(ans,dp[i+1][(j+a[i]-1)%h]);
            }
            dp[i][j]=ans;
        }
    }
    cout<<dp[0][0];
    return 0;
}
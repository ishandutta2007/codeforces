#include <bits/stdc++.h>

using namespace std;
#define int long long
int sn(int x)
{
    if(x>0)
    {
        return 1;
    }
    return 0;
}
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
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    pair <int,int> dp[n+1][2];
    dp[0][0]={0,0};dp[0][1]={0,0};
    for(int i=1;i<=n;++i)
    {
        int x=sn(a[i-1]);
        dp[i][0]=dp[i-1][0];dp[i][1]=dp[i-1][1];
        pair <int,int> z=dp[i-1][(1-x)];
        z.first++;z.second+=a[i-1];
        if(z>=dp[i][x])
        {
            dp[i][x]=z;
        }
    }
    if(dp[n][0]>=dp[n][1])
    {
        cout<<dp[n][0].second<<endl;
    }
    else
    {
        cout<<dp[n][1].second<<endl;
    }
    }
    return 0;
}
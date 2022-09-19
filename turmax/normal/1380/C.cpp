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
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n);
        int u[n];
        for(int i=0;i<n;++i)
        {
            u[i]=((x+a[i]-1)/a[i]);
        }
        int mi[n];
        int curr=1e18;
        for(int i=(n-1);i>=0;--i)
        {
            curr=min(curr,i+u[i]);
            mi[i]=curr;
        }
        int dp[n+1];
        dp[n]=0;
        for(int i=(n-1);i>=0;--i)
        {
            int o=(mi[i]);
            if(o>n) dp[i]=0;
            else if(o<=n) dp[i]=dp[o]+1;
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}
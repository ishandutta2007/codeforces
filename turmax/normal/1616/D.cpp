#include <bits/stdc++.h>

using namespace std;
#define int long long
int sq(int x1,int x2,int x3,int y1,int y2,int y3)
{
    return (x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);
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
        int a[n];int pr[n+1];
        for(int i=0;i<n;++i) cin>>a[i];
        int x;cin>>x;
        for(int i=0;i<n;++i) a[i]-=x;
        pr[0]=0;for(int i=0;i<n;++i) pr[i+1]=pr[i]+a[i];
        /*int dp[n+2];dp[n]=0;dp[n+1]=0;
        for(int i=n-1;i>=0;--i)
        {
            dp[i]=dp[i+1];
            if(a[i]>=x) {dp[i]=dp[i+1]+1;continue;}
            if(i<=n-1) dp[i]=max(dp[i],dp[i+2]+1);
            if(i<=n-2 && a[i]+a[i+1]>=2*x) dp[i]=max(dp[i],dp[i+1]+1);
        }
        cout<<(*max_element(dp,dp+n+1))<<'\n';*/
        int ans=0;int cur=0;int ma=(-1e18);
        while(cur<n)
        {
            if(pr[cur+1]<ma)
            {
                ++cur;
                ma=(-1e18);
                continue;
            }
            else
            {
                ++ans;
                ma=max(ma,pr[cur]);
                ++cur;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
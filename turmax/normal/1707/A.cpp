#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,x;cin>>n>>x;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int dp[n+1];dp[n]=0;for(int i=n-1;i>=0;--i) {if(a[i]<=dp[i+1]) dp[i]=dp[i+1]; else dp[i]=dp[i+1]+1;}
        for(int i=0;i<=n;++i)
        {
            if(dp[i]<=x)
            {
                if(i==0 || dp[i-1]>x)
                {
                    for(int j=0;j<i;++j)
                    {
                        if(a[j]<=x) cout<<1; else cout<<0;
                    }
                    for(int j=i;j<n;++j) {cout<<1;}
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
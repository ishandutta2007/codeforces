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
        int dp[n];
        for(int i=(n-1);i>=0;i--)
        {
            if((i+a[i])>=n)
            {
                dp[i]=a[i];
                continue;
            }
            else
            {
                dp[i]=dp[i+a[i]]+a[i];
                continue;
            }
        }
        cout<<*max_element(dp,dp+n)<<endl;
    }
    return 0;
}
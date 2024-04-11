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
        map <int,int> u;
        for(int i=0;i<n;++i) {cin>>a[i];if(!u.count(a[i])) u[a[i]]=1; else u[a[i]]++;}
        int dp[n+1][2];
        dp[0][0]=0;
        dp[0][1]=0;
        for(int i=1;i<=n;++i)
        {
            if(i!=1 && a[i-1]==a[i-2])
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                continue;
            }
            int o=u[a[i-1]];
            if(o>=2)
            {
                if(i!=1 && (a[i-1]==(a[i-2]+1)))
                {
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][0]+2;
                }
                else
                {
                  dp[i][0]=dp[i-1][1]+1;
                dp[i][1]=dp[i-1][1]+2;
                }
            }
            else
            {
                if(i!=1 && (a[i-1]==(a[i-2]+1)))
                {
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1]+1;
                }
                else
                {
                  dp[i][0]=dp[i-1][1]+1;
                dp[i][1]=dp[i-1][1]+1;
                }
            }
        }
        cout<<dp[n][1]<<'\n';
    }
    return 0;
}
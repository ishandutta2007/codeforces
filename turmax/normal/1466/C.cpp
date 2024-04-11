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
        string s;
        cin>>s;
        int n=s.size();
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        for(int i=1;i<n;++i)
        {
            if(i==1)
            {
                if(s[i]==s[i-1])
                {
                    dp[i+1]=1;
                }
                else
                {
                    dp[i+1]=0;
                }
                continue;
            }
            if(s[i]==s[i-1] && s[i]==s[i-2])
            {
                dp[i+1]=min(dp[i-2]+2,dp[i]+1);
            }
            else if(s[i]==s[i-1])
            {
                dp[i+1]=dp[i-1]+1;
            }
            else if(s[i]==s[i-2])
            {
                if(i>=3 && s[i-1]==s[i-3])
                {
                    dp[i+1]=dp[i-3]+2;
                }
                else
                {
                    dp[i+1]=dp[i-2]+1;
                }
            }
            else
            {
                dp[i+1]=dp[i];
            }
        }
        cout<<dp[n]<<'\n';
    }
    return 0;
}
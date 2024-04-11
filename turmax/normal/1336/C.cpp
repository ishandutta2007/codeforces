#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int dp[n+1][m+1];
    dp[0][m]=1;
    for(int j=0;j<m;++j)
    {
        dp[0][j]=1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            if(j==m)
            {
                dp[i][m]=2*dp[i-1][m];
                dp[i][m]%=p;
                continue;
            }
            int ans=0;
            if(i>(m-j))
            {
                ans=dp[i-1][j];
            }
            else
            {
                if(s1[i-1]==s2[i+j-1])
                {
                    ans=dp[i-1][j];
                }
            }
            //cout<<ans<<" ans "<<endl;
            if(s1[i-1]==s2[j])
            {
                ans+=dp[i-1][j+1];
            }
            ans%=p;
            dp[i][j]=ans;
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    int sum=0;
    for(int i=m;i<=n;++i)
    {
        sum+=dp[i][0];
        sum%=p;
    }
    cout<<sum;
    return 0;
}
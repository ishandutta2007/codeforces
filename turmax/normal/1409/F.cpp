#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s1,s2;
    cin>>s1>>s2;
    if(s2[0]==s2[1])
    {
        int h=0;
        for(auto v:s1)
        {
            if(v==s2[0]) ++h;
        }
        cout<<min((n*(n-1))/2,((h+k)*(h+k-1))/2);
        return 0;
    }
    int dp[n+1][n+1][n+1];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(i!=0)
            {
                dp[0][i][j]=(-1e18);
                continue;
            }
            else
            {
                dp[0][i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            for(int l=0;l<=n;++l)
            {
                dp[i][j][l]=(-1e18);
                if(l!=0 || s1[i-1]==s2[1])
                {
                    int o=l;
                    if(s1[i-1]!=s2[1]) o--;
                    dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][o]+j);
                }
                if((l!=0 || s1[i-1]==s2[0]) && j!=0)
                {
                    int o=l;
                    if(s1[i-1]!=s2[0]) o--;
                    dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-1][o]);
                }
                dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]);
            }
        }
    }
    int ma=0;
    for(int i=0;i<=n;++i)
    {
        ma=max(ma,dp[n][i][k]);
    }
    cout<<ma;
    return 0;
}
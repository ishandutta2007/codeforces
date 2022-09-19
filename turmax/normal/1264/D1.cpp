#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e3+5;
const int p=998244353;
int dp[maxn][maxn];
int dp1[maxn][maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]==')')
        {
            dp1[i][i+1]=1;
        }
        else if(s[i]=='?')
        {
            dp1[i][i+1]=(p+1)/2;
        }
    }
    for(int i=(n-1);i>=0;--i)
    {
        for(int j=(i+2);j<=n;++j)
        {
            if(s[j-1]==')')
            {
                dp1[i][j]=(dp[i][j-1]+1);
            }
            else if(s[j-1]=='?')
            {
                dp1[i][j]=(dp[i][j-1]+dp1[i][j-1]+1)*((p+1)/2);
            }
            else
            {
                dp1[i][j]=dp1[i][j-1];
            }
            dp1[i][j]%=p;
            if(s[i]=='(')
            {
                dp[i][j]=dp1[i+1][j];
            }
            else if(s[i]=='?')
            {
                dp[i][j]=(dp1[i+1][j]+dp[i+1][j])*((p+1)/2);
            }
            else
            {
                dp[i][j]=dp[i+1][j];
            }
            dp[i][j]%=p;
        }
    }
    int ans=dp[0][n];
    for(int i=0;i<n;++i)
    {
        if(s[i]=='?')
        {
            ans*=2;
            ans%=p;
        }
    }
    cout<<ans;
    return 0;
}
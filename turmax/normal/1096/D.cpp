#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string h="hard";
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int dp[n+1][4];
    int s3=0;
    for(int i=0;i<4;++i)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        if(s[i-1]=='h')
        {
            s3+=a[i-1];
        }
        dp[i][0]=s3;
        for(int j=1;j<4;++j)
        {
            if(s[i-1]!=h[j])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j]+a[i-1],dp[i-1][j-1]);
            }
            //cout<<i<<" "<<j<<' '<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][3];
    return 0;
}
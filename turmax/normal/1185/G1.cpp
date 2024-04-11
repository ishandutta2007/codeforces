#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t;
    cin>>n>>t;
    pair <int,int> a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        a[i].second--;
    }
    int sz=(1<<n);
    int dp[t+1][3][sz];
    for(int i=0;i<sz;++i)
    {
    dp[t][0][i]=1;
    dp[t][1][i]=1;
    dp[t][2][i]=1;
    }
    for(int i=(t-1);i>=0;i--)
    {
        for(int j=0;j<3;++j)
        {
            for(int mask=0;mask<sz;++mask)
            {
            int ans=0;
            for(int k=0;k<n;++k)
            {
                if(a[k].second!=j && (i+a[k].first)<=t && (mask & (1<<k)))
                {
                    ans+=dp[i+a[k].first][a[k].second][mask-(1<<k)];
                    ans%=p;
                }
            }
            dp[i][j][mask]=ans;
            //cout<<i<<" "<<j<<" dp[i][j] "<<dp[i][j]<<endl;
            }
        }
    }
    cout<<((dp[0][0][sz-1]+dp[0][1][sz-1]+dp[0][2][sz-1])*((p+1)/2))%p;
    return 0;
}
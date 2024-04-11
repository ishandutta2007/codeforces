#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
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
        int a[n];vector <int> v[n];
        for(int i=0;i<n;++i) {cin>>a[i];a[i]--;v[a[i]].push_back(i);}
        int dp[n+1][n+1];
        int nxt[n];
        for(int i=0;i<n;++i) v[i].push_back(1e9);
        for(int i=0;i<n;++i)
        {
            nxt[i]=*upper_bound(v[a[i]].begin(),v[a[i]].end(),i);
        }
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=n;++j) dp[i][j]=1e18;
        }
        for(int i=0;i<=n;++i)
        {
            dp[i][i]=(-1);
            if(i!=n) dp[i][i+1]=0;
        }
        for(int l=(n-1);l>=0;--l)
        {
            for(int r=(l+2);r<=n;++r)
            {
                 int pos=l;
                 int ans=1e18;
                 int sum=1;
                 vector <int> z;
                 while(true)
                 {
                     //if(l==2 && r==4) cout<<pos<<" pos "<<sum<<" sum "<<endl;
                     ans=min(ans,dp[pos+1][r]+sum);
                     int pos1=nxt[pos];
                     if(pos1>=r)
                     {
                         break;
                     }
                     sum=dp[l][pos1]+1;
                     pos=pos1;
                 }
                 dp[l][r]=ans;
            }
        }
        //cout<<dp[2][4]<<" dp24 "<<endl;
        cout<<dp[0][n]<<endl;
    }
    return 0;
}
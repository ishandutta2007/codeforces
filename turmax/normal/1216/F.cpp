#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int dp[n+1];
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')
        {
            v.push_back(i);
        }
    }
    v.push_back(1e9);
    dp[0]=0;
    for(int i=0;i<n;++i)
    {
        int ans=1e18;
        ans=min(ans,dp[i]+i+1);
        int t=(i-k);
        int z=lower_bound(v.begin(),v.end(),t)-v.begin();
        z=v[z];
        if(z<=(i+k))
        {
            ans=min(ans,z+1+dp[max(0LL,z-k)]);
        }
        dp[i+1]=ans;
    }
    cout<<dp[n];
    return 0;
}
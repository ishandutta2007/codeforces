#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k1;
    cin>>n>>k1;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int low=0;int up=1e9+1;
    while(true)
    {
        if((up-low)==1)
        {
            cout<<up<<endl;
            return 0;
        }
        int k=(low+up)/2;
        vector <int> v;
        for(int i=0;i<n;++i)
        {
            if(a[i]<=k)
            {
                v.push_back(i);
            }
        }
        int dp[v.size()];
        if(v.empty())
        {
            low=k;
            continue;
        }
        if(v[0]==0)
        dp[0]=1;
        else
        dp[0]=2;
        for(int i=1;i<v.size();++i)
        {
            if(v[i]==0)
            dp[i]=1;
            else
            dp[i]=2;
            if(v[i]!=(v[i-1]+1))
            {
                dp[i]=max(dp[i],dp[i-1]+2);
            }
            if(i>=2)
            {
                dp[i]=max(dp[i],dp[i-2]+2);
            }
        }
        int ma=0;
        for(int i=0;i<v.size();++i)
        {
            if(v[i]!=(n-1))
            {
                ++dp[i];
            }
            ma=max(ma,dp[i]);
        }
        if(ma>=k1)
        {
            up=k;
        }
        else
        {
            low=k;
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.begin()+n);
    int dp[n+1];
    dp[0]=0;
    for(int i=0;i<n;++i)
    {
        dp[i+1]=dp[i];
        if(a[i]<=(i+1) && (dp[i+1-a[i]]+1)>dp[i+1])
        {
            dp[i+1]=dp[i+1-a[i]]+1;
        }
    }
    cout<<dp[n]<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
int mex(vector <int> v)
{
    bool used[2]={0};
    for(auto h:v) used[h]=true;
    if(!used[0]) return 0;
    if(!used[1]) return 1;
    return 2;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=0;
            vector <int> v={s[i-1]-'0',t[i-1]-'0'};
            dp[i]=max(dp[i],dp[i-1]+mex(v));
            if(i!=1)
            {
                v={s[i-1]-'0',t[i-1]-'0',s[i-2]-'0',t[i-2]-'0'};
                dp[i]=max(dp[i],dp[i-2]+mex(v));
            }
        }
        cout<<dp[n]<<'\n';
    }
    return 0;
}
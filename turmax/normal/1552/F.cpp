#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;
        vector <vector <int> > u;
        for(int i=0;i<n;++i) {int x,y,z;cin>>x>>y>>z;u.push_back({x,y,z});}
        sort(u.begin(),u.end());
        int dp[n];
        int pr[n+1];pr[0]=0;
        for(int i=0;i<n;++i)
        {
             if(i!=(n-1)) dp[i]=u[i+1][0]-u[i][0];
             else dp[i]=1;
             int j=lower_bound(u.begin(),u.end(),(vector <int>) {u[i][1],-1,-1})-u.begin();
             dp[i]+=(u[j][0]-u[i][1]);
             dp[i]%=p;
             dp[i]+=(pr[i]-pr[j]);
             dp[i]%=p;
             pr[i+1]=pr[i]+dp[i];
             pr[i+1]%=p;
        }
        int ans=u[0][0];
        for(int i=0;i<n;++i)
        {
            if(u[i][2])
            {
                ans+=dp[i];
            }
            else
            {
                if(i!=(n-1)) ans+=(u[i+1][0]-u[i][0]);
                else ans+=1;
            }
            ans%=p;ans+=p;ans%=p;
        }
        cout<<ans;
    }
    return 0;
}
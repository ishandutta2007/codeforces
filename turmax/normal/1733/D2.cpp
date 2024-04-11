#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,x,y;cin>>n>>x>>y;
        string s1,s2;cin>>s1>>s2;
        bool a[n]={0};for(int i=0;i<n;++i) a[i]=(s1[i]-'0'); for(int i=0;i<n;++i) a[i]^=(s2[i]-'0');
        int sum=0;for(int i=0;i<n;++i) sum^=a[i];
        if(sum) {cout<<(-1)<<'\n';continue;}
        vector<int> v;for(int i=0;i<n;++i) if(a[i]) v.push_back(i);
        if(x>=y)
        {
        if(v.size()!=2 || v[1]!=v[0]+1)
        {
            cout<<(v.size()/2)*y<<'\n';
            continue;
        }
        else
        {
            if(n>=4)
            cout<<min(x,2*y)<<'\n';
            else
            cout<<x<<'\n';
        }
        }
        else
        {
        int sz=v.size();
        int dp[sz+1]={0};
        dp[0]=0;
        for(int i=2;i<=sz;++i)
        {
            int cnt=v[i-1]-v[i-2];
            dp[i]=max(dp[i-1],dp[i-2]+y-cnt*x);
        }
        cout<<(v.size()/2)*y-dp[sz]<<'\n';
        }
    }
    return 0;
}
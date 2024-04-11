#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector <pair<int,int> > v;
    int curr=1;
    int ch=a[0];
    for(int i=1;i<n;++i)
    {
        if(a[i]==ch) ++curr;
        else
        {
            v.push_back({ch,curr});
            curr=1;
            ch=a[i];
        }
    }
    v.push_back({ch,curr});
    vector <int> z;
    for(int i=0;i<v.size();++i) z.push_back(v[i].first);
    int ans=v.size();
    int dp[v.size()+1];
    vector <int> u[n+1];
    for(int i=0;i<z.size();++i) u[z[i]].push_back(i);
    dp[0]=0;
    //for(auto h:z) cout<<h<<' ';
    //cout<<endl;
    for(int i=1;i<=v.size();++i)
    {
        dp[i]=dp[i-1];
        int last1,last2;
        if(i>=v.size()) last1=0;
        else last1=z[i];
        if((i+1)>=v.size()) last2=0;
        else last2=z[i+1];
        int beg1,beg2;
        if(u[last1].size() && u[last1][0]<=(i-1))
        {
            beg1=u[last1][lower_bound(u[last1].begin(),u[last1].end(),i)-u[last1].begin()-1];
            dp[i]=max(dp[i],dp[beg1]+1);
        }
        if(u[last2].size() && u[last2][0]<=(i-1))
        {
            beg2=u[last2][lower_bound(u[last2].begin(),u[last2].end(),i)-u[last2].begin()-1];
            dp[i]=max(dp[i],dp[beg2]+1);
        }
    }
    cout<<ans-dp[v.size()];
    return 0;
}
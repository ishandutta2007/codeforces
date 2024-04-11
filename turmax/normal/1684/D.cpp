#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        int a[n];for(int i=0;i<n;++i) cin>>a[i];
        vector<pair<int,int> > v;for(int i=0;i<n;++i) v.push_back({a[i]+i,i});
        sort(v.begin(),v.end());reverse(v.begin(),v.end());
        bool ok[n];for(int i=0;i<n;++i) ok[i]=true;
        for(int i=0;i<m;++i) {ok[v[i].second]=false;}
        int sum=0,ans=0;
        for(int i=0;i<n;++i)
        {
            if(!ok[i])
            {
                ++sum;
            }
            else {ans+=(a[i]+sum);}
        }
        cout<<ans<<'\n';
    }
    return 0;
}
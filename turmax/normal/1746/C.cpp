#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        vector<pair<int,int> > v; for(int i=0;i<n-1;++i) v.push_back({a[i]-a[i+1],i});
        sort(v.begin(),v.end());vector<int> res(n);
        res[0]=1;
        for(int i=0;i<v.size();++i) res[i+1]=v[i].second+2;
        for(auto h:res) cout<<h<<' ';
        cout<<'\n';
    }
    return 0;
}
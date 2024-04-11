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
        vector<int> v0,v1;for(int i=0;i<n;++i) {if(a[i]%2==0) v0.push_back(i); else v1.push_back(i);}
        vector<pair<int,int> > res;
        if(a[0]%2==1)
        {
        for(int i=0;i<((int) v1.size())-1;++i)
        {
            res.push_back({v1[i],v1[i+1]});
        }
        reverse(res.begin(),res.end());
        for(auto h:v0)
        {
            res.push_back({0,h});
        }
        }
        else
        {
        for(int i=0;i<((int) v0.size())-1;++i)
        {
            res.push_back({v0[i],v0[i+1]});
        }
        reverse(res.begin(),res.end());
        for(auto h:v1)
        {
            res.push_back({0,h});
        }
        }
        cout<<res.size()<<'\n';
        for(auto [x,y]:res)
        {
            cout<<x+1<<' '<<y+1<<'\n';
        }
    }
    return 0;
}
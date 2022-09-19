#include <bits/stdc++.h>

using namespace std;
#define int long long
pair <int,int> go(pair <int,int> a,pair <int,int> b)
{
    if(a.first<b.second)
    {
        a.first=min(a.first,b.first);
    }
    if(a.second>b.first)
    {
        a.second=max(a.second,b.second);
    }
    return a;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,x,m;
    cin>>n>>x>>m;
    x--;
    vector <pair<int,int> > a;
    pair <int,int> d=make_pair(x,x+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        u--;
        a.push_back({u,v});
        d=go(d,{u,v});
    }
    cout<<d.second-d.first<<endl;
    }
    return 0;
}
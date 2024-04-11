#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n,x;
    cin>>n;
    vector <pair<int,int> > a(n);
    for(int i=0;i<n;++i)
    {
        cin>>x;
        a[i]={x,0};
    }
    int q;
    cin>>q;
    int t;
    int u,v;
    int tim=0;
    vector <pair<int,int> > b;
    vector <int> c;
    for(int i=0;i<q;++i)
    {
        ++tim;
        cin>>t;
        if(t==1)
        {
            cin>>u>>v;
            u--;
            a[u]={v,tim};
        }
        if(t==2)
        {
            cin>>u;
            b.push_back({u,tim});
            c.push_back(tim);
        }
    }
    reverse(b.begin(),b.end());
    int ma=0;
    map <int,int> h;
    for(int i=0;i<b.size();++i)
    {
        b[i].first=max(ma,b[i].first);
        h[b[i].second]=b[i].first;
        ma=b[i].first;
    }
    reverse(b.begin(),b.end());
    if(c.size()==0)
    {
        for(int i=0;i<n;++i)
        {
            cout<<a[i].first<<" ";
        }
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        if(a[i].second<=c[c.size()-1])
        {
            cout<<max(h[*(lower_bound(c.begin(),c.end(),a[i].second))],a[i].first)<<" ";
        }
        else
        {
            cout<<a[i].first<<endl;
        }
    }
    return 0;
}
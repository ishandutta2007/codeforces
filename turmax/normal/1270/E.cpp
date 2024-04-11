#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(int x)
{
    if(x%2==0)
    {
        return x/2;
    }
    if(x>=0)
    {
        return x/2;
    }
    return -((-x)/2)-1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <pair<int,int> > a(n);
    int x,y;
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        a[i].first=x;
        a[i].second=y;
    }
    while(true)
    {
    v.clear();
    for(int i=0;i<n;++i)
    {
        if((a[i].first+a[i].second)%2==0)
        {
            v.push_back(i);
        }
    }
    if(v.size()!=0 && v.size()!=n)
    {
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    return 0;
    }
    v.clear();
    for(int i=0;i<n;++i)
    {
        if((a[i].first%2)==0)
        {
            v.push_back(i);
        }
    }
    if(v.size()!=0 && v.size()!=n)
    {
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    return 0;
    }
    for(int i=0;i<n;++i)
    {
        a[i].first=go(a[i].first);
        a[i].second=go(a[i].second);
    }
    }
    return 0;
}
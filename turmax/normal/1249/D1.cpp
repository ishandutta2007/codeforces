#include <bits/stdc++.h>

using namespace std;
#define int long long
map <pair<int,int>,vector <int> > u;
int cou(int x,vector <pair<int,int> > &a)
{
    int n=a.size();
    int sum=0;
    for(int i=0;i<n;++i)
    {
        if(a[i].first<=x && a[i].second>=x)
        {
            ++sum;
        }
    }
    return sum;
}
int go(pair <int,int> d,vector <pair<int,int> > &a)
{
    int n=a.size();
    for(int i=0;i<n;++i)
    {
        if(a[i]==d)
        {
            return i;
        }
    }
}
int del(int x,vector<pair<int,int> > &a)
{
    int n=a.size();
    vector <pair<int,int> > v;
    for(int i=0;i<n;++i)
    {
        if(a[i].first<=x && a[i].second>=x)
        {
            v.push_back({a[i].second,a[i].first});
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    pair <int,int> d;
    d.first=v[0].second;
    d.second=v[0].first;
    a.erase(a.begin()+go(d,a));
    int y=u[d][u[d].size()-1];
    u[d].erase(u[d].begin()+u[d].size()-1);
    return y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector <pair<int,int> > a(n);
    vector <int> z;
    int l,r;
    for(int i=0;i<n;++i)
    {
        cin>>l>>r;
        a[i]={l,r};
        if(u.count({l,r})==1)
        {
            u[{l,r}].push_back(i);
        }
        else
        {
            z.clear();
            z.push_back(i);
            u[{l,r}]=z;
        }
    }
    sort(a.begin(),a.end());
    int l1=-200;
    int r1=200;
    vector <int> res;
    for(int i=l1;i<=r1;++i)
    {
        while(cou(i,a)>k)
        {
            res.push_back(del(i,a));
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]+1<<" ";
    }
    return 0;
}
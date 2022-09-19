#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <pair <int,int> > go1(int k)
{
    int n=(1<<k);
    vector <pair<int,int> > ans;
    for(int i=0;i<(n/2);++i)
    {
        ans.push_back({2*i,2*i+1});
    }
    if(k==1)
    {
        return ans;
    }
    vector <pair<int,int> > u=go1(k-1);
    for(auto h:u)
    {
        ans.push_back({2*h.first,2*h.second});
        ans.push_back({2*h.first+1,2*h.second+1});
    }
    return ans;
}
vector <pair<int,int> > go(int n)
{
    int k=0;
    while((1<<k)<=n)
    {
        ++k;
    }
    k--;
    vector <pair<int,int> > v=go1(k);
    vector <pair<int,int> > ans;
    for(auto h:v)
    {
        ans.push_back({h.first+n-(1<<k),h.second+n-(1<<k)});
    }
    for(auto h:v)
    {
        ans.push_back(h);
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n<=2) {cout<<0;return 0;}
    vector <pair<int,int> > v=go(n);
    cout<<v.size()<<'\n';
    for(auto h:v)
    {
        cout<<h.first+1<<' '<<h.second+1<<'\n';
    }
    return 0;
}
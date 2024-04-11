#include <bits/stdc++.h>

using namespace std;
#define int long long
set <int> h;
map <int,int> u;
int mi(int x)
{
    u[x]--;
    if(!u[x])
    {
        h.erase(x);
    }
}
int pl(int x)
{
    u[x]++;
    if(u[x]==1)
    {
        h.insert(x);
    }
}
int getans()
{
    set <int>::iterator it=h.end();
    it--;
    return (*it)-(*h.begin());
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a[6];
    for(int i=0;i<6;++i) cin>>a[i];
    sort(a,a+6);
    reverse(a,a+6);
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;++i) cin>>b[i];
    vector <pair<int,pair<int,int> > > v;
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<6;++j)
        {
            v.push_back({2*b[i]-a[j]-a[j-1],{i,b[i]-a[j]}});
        }
    }
    sort(v.begin(),v.end());
    int u[n];
    for(int i=0;i<n;++i)
    {
        pl(b[i]-a[0]);
        u[i]=(b[i]-a[0]);
    }
    int ans=getans();
    for(auto h:v)
    {
        int i=h.second.first;
        int val=h.second.second;
        mi(u[i]);
        //cout<<i<<" i "<<u[i]<<" u[i] "<<endl;
        u[i]=val;
        pl(u[i]);
        ans=min(ans,getans());
    }
    cout<<ans;
    return 0;
}
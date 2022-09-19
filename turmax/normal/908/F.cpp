#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv(int l,int r,vector<int> a,vector<int> b)
{
    int u=r-l;int ma1=0,ma2=0,ma3=r-l;
    if(a.empty() && b.empty())
    {
        if(l<0 || r>1e17) return 0;
        else return r-l;
    }
    if(!a.empty()) {
    if(l>=0) {a.insert(a.begin(),l);} if(r<1e17) {a.push_back(r);}}
    if(!b.empty())
    {
    if(l>=0) b.insert(b.begin(),l); if(r<1e17) b.push_back(r);}
    for(int i=0;i<((int) a.size())-1;++i) {u+=(a[i+1]-a[i]);ma1=max(ma1,a[i+1]-a[i]);}
    for(int i=0;i<((int) b.size())-1;++i) {u+=(b[i+1]-b[i]);ma2=max(ma2,b[i+1]-b[i]);}
    if(a.empty() && l>=0 && r<1e17)
    {
        return u-ma2;
    }
    if(b.empty() && l>=0 && r<1e17)
    {
        return u-ma1;
    }
    return u-max(ma3,ma1+ma2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;vector<pair<char,int> > a;vector<int> b={(int) -1e18};
    for(int i=0;i<n;++i) {char s;int x;cin>>x>>s;a.push_back({s,x});if(s=='G') b.push_back(x);}
    b.push_back(1e18);
    pair<vector<int>,vector<int> > h[b.size()+1];
    for(auto [s,x]:a)
    {
        if(s=='R')
        {
            h[lower_bound(b.begin(),b.end(),x)-b.begin()].first.push_back(x);
        }
        if(s=='B')
        {
            h[lower_bound(b.begin(),b.end(),x)-b.begin()].second.push_back(x);
        }
    }
    int ans=0;
    for(int i=0;i<b.size()-1;++i)
    {
        ans+=slv(b[i],b[i+1],h[i+1].first,h[i+1].second);
    }
    cout<<ans;
    return 0;
}
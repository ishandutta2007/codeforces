#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
int f[maxn];
int get(int x)
{
    int ans=4e18;
    while(x<maxn) {ans=min(ans,f[x]);x=x | (x+1);}
    return ans;
}
void mi(int pos,int val)
{
    while(pos>=0)
    {
        f[pos]=min(f[pos],val);pos=((pos & (pos+1)) -1);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) f[i]=4e18;
    int n,q;cin>>n>>q;int a[n],b[n];for(int i=0;i<n;++i) cin>>a[i]>>b[i];
    vector <pair<int,int> > que[n+1];
    vector <int> v;for(int i=0;i<n;++i) {while(!v.empty() && b[v.back()]>b[i]) v.pop_back(); if(!v.empty()) {int val=(b[v.back()]+b[i])*(a[i]-a[v.back()]);que[i].push_back({v.back(),val});} v.push_back(i);}
    v.clear();for(int i=n-1;i>=0;--i) {while(!v.empty() && b[v.back()]>b[i]) v.pop_back(); if(!v.empty()) {int val=(b[v.back()]+b[i])*(a[v.back()]-a[i]);que[v.back()].push_back({i,val});} v.push_back(i);}
    vector <pair<int,int> > que1[n+1];int ans[q]={0};for(int i=0;i<q;++i) {int l,r;cin>>l>>r;--l;que1[r].push_back({l,i});}
    for(int r=0;r<=n;++r) {for(auto h:que1[r]) {ans[h.second]=get(h.first);} for(auto h:que[r]) mi(h.first,h.second);}
    for(auto h:ans) cout<<h<<'\n';
    return 0;
}
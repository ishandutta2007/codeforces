#include <bits/stdc++.h>

using namespace std;
#define int long long
int sum=0;
vector <pair<int,int> > v1;
vector <pair<int,int> > v2;
const int maxn=4e5+5;
vector <pair<int,int> > h[4*maxn];
vector <pair<int,int> > l[maxn];
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=r || tr<=l) return 0;
    if(tl>=l && tr<=r)
    {
        pair <int,int> z=h[node][upper_bound(h[node].begin(),h[node].end(),make_pair(r,(int) 1e18))-h[node].begin()-1];
        return z.second;
    }
    int tm=(tl+tr)/2;
    return max(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        h[node]=l[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    for(auto z:h[2*node+1]) h[node].push_back(z);
    for(auto z:h[2*node+2]) h[node].push_back(z);
    sort(h[node].begin(),h[node].end());
}
int go(vector <int> a,vector <int> b)
{
    int n=a.size();
    for(int i=0;i<4*n;++i) {h[i].clear();;if(i<n) {l[i].clear();l[i].push_back({-1e9,0});}}
    vector <int> mom;
    for(auto h:a) mom.push_back(h);
    for(auto h:b) mom.push_back(h);
    sort(mom.begin(),mom.end());
    mom.erase(unique(mom.begin(),mom.end()),mom.end());
    v1.clear();v2.clear();
    for(int i=0;i<n;++i)
    {
        if(a[i]>=b[i]) v1.push_back({lower_bound(mom.begin(),mom.end(),b[i])-mom.begin(),lower_bound(mom.begin(),mom.end(),a[i])-mom.begin()});
        else v2.push_back({lower_bound(mom.begin(),mom.end(),a[i])-mom.begin(),lower_bound(mom.begin(),mom.end(),b[i])-mom.begin()});
    }
    int op[mom.size()]={0};
    for(int i=0;i<v2.size();++i)
    {
        op[v2[i].first]=max(op[v2[i].first],v2[i].second);
        l[v2[i].first].push_back((make_pair(v2[i].second,mom[v2[i].second]-mom[v2[i].first])));
    }
    for(int i=0;i<n;++i) sort(l[i].begin(),l[i].end());
    build(0,0,n);
    int sufma[mom.size()];
    sufma[0]=op[0];
    for(int i=1;i<mom.size();++i) sufma[i]=max(sufma[i-1],op[i]);
    int ans=0;
    for(auto h:v1)
    {
        int j=sufma[h.first];
        int j1=min(j,h.second);
        ans=max(ans,2*(mom[j1]-mom[h.first]));
    }
    for(auto h:v1)
    {
        ans=max(ans,2*get(0,0,n,h.first,h.second));
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);vector <int> b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    for(int i=0;i<n;++i) sum+=abs(a[i]-b[i]);
    int ans=max(go(a,b),go(b,a));
    cout<<(sum-ans);
    return 0;
}
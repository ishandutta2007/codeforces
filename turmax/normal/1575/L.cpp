#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=8e5;
const int maxn1=4e5;
vector <int> z[maxn];
int dp[maxn];
int a[maxn];
int t[4*maxn];
int get(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos) return (-1e18);
    if((tr-tl)==1) return t[node];
    int tm=(tl+tr)/2;
    return max({t[node],get(2*node+1,tl,tm,pos),get(2*node+2,tm,tr,pos)});
}
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r)
    {
        t[node]=max(t[node],val);
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
}
vector <pair<int,int> > r;
void go(int x)
{
    int val=a[x];
    int val2=a[x]-x;
    //to(0,0,maxn,0,val2+maxn1+1,dp[x]);
    r.push_back({val2+maxn1+1,dp[x]});
}
void upd(int x)
{
    if(a[x]<=(x+1))
    {
        dp[x]=max(dp[x],1LL);
    }
    int val=a[x];
    int val2=a[x]-x;
    //to(0,0,maxn,0,val2+maxn1,dp[x]+1);
    dp[x]=max(dp[x],get(0,0,maxn,val2+maxn1)+1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<4*maxn;++i) {t[i]=(-1e18);} for(int i=0;i<maxn;++i) dp[i]=(-1e18);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {cin>>a[i];z[a[i]].push_back(i);}
    vector <pair<int,int> > z;
    for(int i=0;i<n;++i) z.push_back({a[i],i});
    sort(z.begin(),z.end());
    for(int i=0;i<z.size();++i) {if(i==0 || z[i].first!=z[i-1].first) {for(auto l:r) {to(0,0,maxn,0,l.first,l.second);}r.clear();}pair <int,int> h=z[i];upd(h.second);go(h.second);}
    cout<<max(0LL,*max_element(dp,dp+n));
    return 0;
}
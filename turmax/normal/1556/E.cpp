#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int h[maxn];
pair <int,int> t[4*maxn];
pair <int,int> merg(pair <int,int> u,pair <int,int> v)
{
    return {min(u.first,v.first),max(u.second,v.second)};
}
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        t[node]={h[tl],h[tl]};
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    t[node]=merg(t[2*node+1],t[2*node+2]);
}
pair <int,int> get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return t[node];
    }
    if(tl>=r || tr<=l)
    {
        return {1e18,-1e18};
    }
    int tm=(tl+tr)/2;
    return merg(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int a[n],b[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    h[0]=0;
    for(int i=0;i<n;++i)
    {
        h[i+1]=h[i]+b[i]-a[i];
    }
    build(0,0,n+1);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        if(h[l]!=h[r])
        {
            cout<<(-1)<<'\n';
            continue;
        }
        pair <int,int> o=get(0,0,n+1,l,r);
        if(o.first==h[l])
        {
            cout<<(o.second-h[l])<<'\n';
        }
        else
        {
            cout<<(-1)<<'\n';
        }
    }
    return 0;
}
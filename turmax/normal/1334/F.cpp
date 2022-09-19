#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
int t[4*maxn];
int v[maxn];
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        v[tl]=node;
        if(tl!=0)
        t[node]=1e18;
        else
        t[node]=0;
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
}
void pl(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r)
    {
        t[node]+=val;
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)/2;
    pl(2*node+1,tl,tm,l,r,val);pl(2*node+2,tm,tr,l,r,val);
}
int get(int node,int tl,int tr,int pos)
{
    if(pos>=tr || pos<tl) return 0;
    if((tr-tl)==1)
    {
        return t[node];
    }
    t[2*node+1]+=t[node];t[2*node+2]+=t[node];
    t[node]=0;
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,pos)+get(2*node+2,tm,tr,pos);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    build(0,0,maxn);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int p[n];
    for(int i=0;i<n;++i) cin>>p[i];
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;++i) cin>>b[i];
    for(int i=0;i<n;++i)
    {
        int o=lower_bound(b,b+m,a[i])-b;
        if(p[i]>=0)
        pl(0,0,maxn,0,o+1,p[i]);
        else
        {
        pl(0,0,maxn,0,maxn,p[i]);
        }
        if(b[o]==a[i]){
        int x=get(0,0,maxn,o);
        //cout<<o<<" o "<<endl;
        //cout<<x<<" x "<<endl;
        get(0,0,maxn,o+1);
        t[v[o+1]]=min(t[v[o+1]],x-p[i]);
        }
    }
    int ans=get(0,0,maxn,m);
    if(ans<=1e15)
    {
        cout<<"YES"<<endl;
        cout<<ans;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
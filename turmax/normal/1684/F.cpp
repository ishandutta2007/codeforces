#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int t[4*maxn];
map<int,int> u;
map<int,vector<int> > d;
int sz;
int get(int node,int tl,int tr,int pos)
{
    if(pos<tl || pos>=tr) return 0;
    if(tr-tl==1) {return t[node];}
    int tm=(tl+tr)/2;
    return max(t[node],max(get(2*node+1,tl,tm,pos),get(2*node+2,tm,tr,pos)));
}
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(l==r) return;
    if(tl>=l && tr<=r)
    {
        t[node]=max(t[node],val);return;
    }
    if(tl>=r || tr<=l) return;
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
}
void to(int l,int r,int val)
{
    //cout<<l<<' '<<r<<' '<<val<<" tgfr "<<endl;
    to(0,0,sz,l,r,val);
}
int get(int pos)
{
    return get(0,0,sz,pos);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;
    while(t1--)
    {
        d.clear();
        int n,m;cin>>n>>m;sz=n+1;for(int i=0;i<4*sz;++i) t[i]=0;
        int a[n];int val[n]={0};for(int i=0;i<n;++i) {cin>>a[i];d[a[i]].push_back(i);}
        u.clear();int nxt[n];for(int i=n-1;i>=0;--i) {if(!u.count(a[i])) nxt[i]=(-1); else nxt[i]=u[a[i]]; u[a[i]]=i;}
        for(int i=0;i<m;++i) {int l,r;cin>>l>>r;--l;val[l]=max(val[l],r);}
        int ma=0;
        for(int i=0;i<n;++i)
        {
            ma=max(ma,val[i]);
            int o=nxt[i];
            //cout<<i<<" i "<<ma<<" ma "<<nxt[i]<<" nxt[i] "<<endl;
            if(o!=(-1) && o<ma)
            {
                to(0,i+1,i+1);
                to(o+1,sz,1e9);
                int h=d[a[i]][lower_bound(d[a[i]].begin(),d[a[i]].end(),ma)-d[a[i]].begin()-1];
                //cout<<i<<" i "<<o<<" o "<<ma<<" ma "<<endl;
                to(i+1,o+1,h+1);
            }
        }
        int ans=1e9;
        for(int i=0;i<n;++i)
        {
            int x=get(i);
            if(x!=((int) 1e9))
            {
                ans=min(ans,x-i);
            }
        }
        if(ans==1e9) {cout<<(-1)<<'\n';}
        else {cout<<max(ans,0LL)<<'\n';}
    }
    return 0;
}
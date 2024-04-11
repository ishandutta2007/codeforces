#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e5+5;
int d;
bool a[maxn];int cnt[4*maxn];int sum[4*maxn];int sumsq[4*maxn];int fe[maxn];int delay[4*maxn];
void pl1(int pos) {while(pos<maxn) {fe[pos]++;pos|=(pos+1);}}
void mi1(int pos) {while(pos<maxn) {fe[pos]--;pos|=(pos+1);}}
int get1(int pos) {int ans=0;while(pos>=0) {ans+=fe[pos];pos&=(pos+1);--pos;} return ans;}
void push(int node)
{
    int x=delay[node];delay[node]=0;
    sumsq[2*node+1]+=(2*x*sum[2*node+1]+x*x*cnt[2*node+1]);sum[2*node+1]+=(x*cnt[2*node+1]);delay[2*node+1]+=x;
    sumsq[2*node+2]+=(2*x*sum[2*node+2]+x*x*cnt[2*node+2]);sum[2*node+2]+=(x*cnt[2*node+2]);delay[2*node+2]+=x;
    cnt[node]=cnt[2*node+1]+cnt[2*node+2];sum[node]=sum[2*node+1]+sum[2*node+2];sumsq[node]=sumsq[2*node+1]+sumsq[2*node+2];
}
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1)
    {
        cnt[node]=1;sum[node]=val;sumsq[node]=val*val;return;
    }
    push(node);
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    cnt[node]=cnt[2*node+1]+cnt[2*node+2];sum[node]=sum[2*node+1]+sum[2*node+2];sumsq[node]=sumsq[2*node+1]+sumsq[2*node+2];
}
void del(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1)
    {
        cnt[node]=0;sum[node]=0;sumsq[node]=0;return;
    }
    push(node);
    int tm=(tl+tr)/2;
    del(2*node+1,tl,tm,pos);del(2*node+2,tm,tr,pos);
    cnt[node]=cnt[2*node+1]+cnt[2*node+2];sum[node]=sum[2*node+1]+sum[2*node+2];sumsq[node]=sumsq[2*node+1]+sumsq[2*node+2];
}
void pl(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r)
    {
        delay[node]+=val;sumsq[node]+=(2*val*sum[node]+val*val*cnt[node]);sum[node]+=(val*cnt[node]);return;
    }
    if(tl>=r || tr<=l) return;
    push(node);
    int tm=(tl+tr)/2;
    pl(2*node+1,tl,tm,l,r,val);pl(2*node+2,tm,tr,l,r,val);
    cnt[node]=cnt[2*node+1]+cnt[2*node+2];sum[node]=sum[2*node+1]+sum[2*node+2];sumsq[node]=sumsq[2*node+1]+sumsq[2*node+2];
}
void pl(int x)
{
    pl1(x);int o=get1(x+d)-get1(x);
    to(0,0,maxn,x,o);
    pl(0,0,maxn,max(0LL,x-d),x,1);
}
void mi(int x)
{
    mi1(x);
    del(0,0,maxn,x);
    pl(0,0,maxn,max(0LL,x-d),x,-1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;cin>>q>>d;
    while(q--)
    {
        int x;cin>>x;if(!a[x]) {a[x]=1;pl(x);} else {a[x]=0;mi(x);}
        cout<<(sumsq[0]-sum[0])/2<<'\n';
    }
    return 0;
}
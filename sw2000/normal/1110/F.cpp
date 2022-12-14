#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN    "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=5e5+10;
const ll mod=998244353;

int n,q,R[N];
ll mi[N<<2],lazy[N<<2],dis[N],ans[N];
vector<pii>edg[N];
vi ask[N];
pii br[N];
void build(int o=1,int l=1,int r=n){
    if(l==r){
        mi[o]=dis[l];
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}
void pushdown(int o){
    if(lazy[o]){
        lazy[lo]+=lazy[o];
        lazy[ro]+=lazy[o];
        mi[lo]+=lazy[o];
        mi[ro]+=lazy[o];
        lazy[o]=0;
    }
}
void update(int ql,int qr,int v,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        lazy[o]+=v;
        mi[o]+=v;
        return;
    }
    pushdown(o);
    if(ql<=mid)update(ql,qr,v,lo,l,mid);
    if(qr>mid)update(ql,qr,v,ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}
ll query(int ql,int qr,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        return mi[o];
    }
    pushdown(o);
    ll ret=linf;
    if(ql<=mid)Min(ret,query(ql,qr,lo,l,mid));
    if(qr>mid)Min(ret,query(ql,qr,ro,mid+1,r));
    return ret;
}
void dfs(int u){
    R[u]=u;
    for(auto i:edg[u]){
        int v,w;tie(v,w)=i;
        dis[v]=dis[u]+w;
        dfs(v);
        R[u]=R[v];
    }
    if(edg[u].size())dis[u]=linf;
}
void dfs2(int u){
    for(auto i:ask[u]){
        ans[i]=query(br[i].fi,br[i].se);
    }
    for(auto i:edg[u]){
        int v,w;tie(v,w)=i;
        update(1,n,w);
        update(v,R[v],-2*w);
        dfs2(v);
        update(1,n,-w);
        update(v,R[v],2*w);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int f,w;cin>>f>>w;
        edg[f].push_back({i,w});
    }
    dfs(1);
    build();
    for(int i=0;i<q;i++){
        int a;cin>>a;
        ask[a].push_back(i);
        cin>>br[i].fi>>br[i].se;
    }
    dfs2(1);
    for(int i=0;i<q;i++)cout<<ans[i]<<endl;
}
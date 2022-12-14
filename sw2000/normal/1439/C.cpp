#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
typedef long long ll;
typedef long double ld;
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
const int N=2e5+10,M=400;
const ll mod=1e9+7;

int n,m;
ll sum[N<<2],mi[N<<2],lazy[N<<2];
void pushdown(int o,int l,int r){
    if(lazy[o]){
        lazy[lo]=lazy[ro]=mi[lo]=mi[ro]=lazy[o];
        sum[lo]=lazy[o]*(mid-l+1);
        sum[ro]=lazy[o]*(r-mid);
        lazy[o]=0;
    }
}
void pushup(int o){
    mi[o]=min(mi[lo],mi[ro]);
    sum[o]=sum[lo]+sum[ro];
}
void build(int o=1,int l=1,int r=n){
    if(l==r){
        cin>>sum[o];
        mi[o]=sum[o];
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    pushup(o);
}
int query(int v,int o=1,int l=1,int r=n){
    if(l==r)return l;
    pushdown(o,l,r);
    if(mi[lo]<=v)return query(v,lo,l,mid);
    else if(mi[ro]<=v)return query(v,ro,mid+1,r);
    else return inf;
}
void update(int ql,int qr,ll v,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        lazy[o]=v;
        sum[o]=(r-l+1)*v;
        mi[o]=v;
        return;
    }
    pushdown(o,l,r);
    if(ql<=mid)update(ql,qr,v,lo,l,mid);
    if(qr>mid)update(ql,qr,v,ro,mid+1,r);
    pushup(o);
}
int query_num(int p,int &y,int o=1,int l=1,int r=n){
    if(y<mi[o])return 0;
    if(l>=p){
        if(y>=sum[o]){
            y-=sum[o];
            return r-l+1;
        }
        pushdown(o,l,r);
        int ret=0;
        ret+=query_num(p,y,lo,l,mid);
        ret+=query_num(p,y,ro,mid+1,r);
        return ret;
    }
    pushdown(o,l,r);
    int ret=0;
    if(p<=mid)ret+=query_num(p,y,lo,l,mid);
    ret+=query_num(p,y,ro,mid+1,r);
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m;
    build();
    while(m--){
        int op,x,y;cin>>op>>x>>y;
        if(op==1){
            int ql=query(y);
            if(ql<=x)update(ql,x,y);
        }
        else{
            cout<<query_num(x,y)<<endl;
        }
    }
}
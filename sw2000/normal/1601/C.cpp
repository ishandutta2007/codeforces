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
const int N=1e6+10,M=500;
const ll mod=998244353;

int n,m,tot;
int lazy[N<<2],ar[N],br[N],rk[N],pos[N],cr[N];
pii mi[N<<2];
void build(int o=1,int l=1,int r=n){
    lazy[o]=0;
    if(l==r){
        mi[o]={l,l};
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
        mi[lo].fi+=lazy[o];
        mi[ro].fi+=lazy[o];
        lazy[o]=0;
    }
}
void add(int ql,int qr,int v,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        mi[o].fi+=v;
        lazy[o]+=v;
        return;
    }
    pushdown(o);
    if(ql<=mid)add(ql,qr,v,lo,l,mid);
    if(qr>mid)add(ql,qr,v,ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}
template<class T>struct BIT{
    vector<T>a;
    BIT(int n):a(n,0){}
    void add(int p,T x){for(p++;p<=a.size();p+=p&-p)a[p-1]+=x;}
    T sum(int p){T ret=0;for(p++;p>0;p&=p-1)ret+=a[p-1];return ret;}
};
ll solve(){
    cin>>n>>m;
    build();
    vi lower,upper;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        cr[i]=ar[i];
        lower.push_back(i);
        upper.push_back(i);
    }
    sort(lower.begin(),lower.end(),[&](int a,int b){
        return ar[a]>ar[b];
    });
    sort(upper.begin(),upper.end(),[&](int a,int b){
        return ar[a]>ar[b];
    });
    for(int j=1;j<=m;j++){
        cin>>br[j];
        rk[j]=j;
    }
    sort(rk+1,rk+1+m,[&](int a,int b){
        return br[a]<br[b];
    });
    ll ret=0;
    for(int i=1;i<=m;i++){
        int id=rk[i];
        while(!lower.empty()&&ar[lower.back()]<br[id]){
            int j=lower.back();lower.pop_back();
            add(j,n,-1);
        }
        while(!upper.empty()&&ar[upper.back()]<=br[id]){
            int j=upper.back();upper.pop_back();
            add(j,n,-1);
        }
        auto tmp=min((pii){0,0},mi[1]);
        K(tmp)
        ret+=n-lower.size()+tmp.fi;
    }

    sort(cr+1,cr+1+n);
    tot=unique(cr+1,cr+1+n)-cr-1;
    BIT<int>sw(tot+1);
    for(int i=n;i;i--){
        int p=lower_bound(cr+1,cr+1+tot,ar[i])-cr;
        ret+=sw.sum(p-1);
        sw.add(p,1);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}
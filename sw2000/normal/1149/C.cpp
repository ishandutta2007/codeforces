#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"}";Err(x...);}
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
const int N=2e5+10;
const ll mod=998244353;

int n,m;
char s[N];
struct A{
    int sum,lmi,lma,rmi,rma,maxl,maxr,ans;
}ar[N<<2];
void Err(A a){cerr<<a.sum<<' '<<a.lmi<<' '<<a.lma<<' '<<a.rmi<<' '<<a.rma<<' '<<a.maxl<<' '<<a.maxr<<' '<<a.ans; }
void pushup(int o){
    ar[o].sum=ar[lo].sum+ar[ro].sum;
    ar[o].lmi=min(ar[lo].lmi,ar[lo].sum+ar[ro].lmi);
    ar[o].lma=max(ar[lo].lma,ar[lo].sum+ar[ro].lma);
    ar[o].rmi=min(ar[ro].rmi,ar[ro].sum+ar[lo].rmi);
    ar[o].rma=max(ar[ro].rma,ar[ro].sum+ar[lo].rma);
    ar[o].maxl=max(ar[lo].maxl,ar[ro].maxl-ar[lo].sum);
    Max(ar[o].maxl,-ar[lo].lmi+ar[lo].rma+ar[ro].lma);
    ar[o].maxr=max(ar[ro].maxr,ar[lo].maxr+ar[ro].sum);
    Max(ar[o].maxr,ar[ro].rma-ar[ro].lmi-ar[lo].rmi);
    ar[o].ans=max(ar[lo].ans,ar[ro].ans);
    Max(ar[o].ans,ar[lo].maxr+ar[ro].lma);
    Max(ar[o].ans,ar[ro].maxl-ar[lo].rmi);
    Max(ar[o].ans,max(ar[o].maxl,ar[o].maxr));
}
void build(int o=1,int l=1,int r=n){
    if(l==r){
        if(s[l]==')')ar[o]={-1,-1,0,-1,0,1,1,1};
        else ar[o]={1,0,1,0,1,1,1,1};
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    pushup(o);
//    K(l,r,ar[o])
}
void modify(int p,int o=1,int l=1,int r=n){
    if(l==r){
        if(s[l]==')')ar[o]={-1,-1,0,-1,0,1,1,1};
        else ar[o]={1,0,1,0,1,1,1,1};
        return;
    }
    if(p<=mid)modify(p,lo,l,mid);
    else modify(p,ro,mid+1,r);
    pushup(o);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m;n=n*2-2;
    cin>>s+1;
    build();
    cout<<ar[1].ans<<endl;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        swap(s[a],s[b]);
        modify(a);
        modify(b);
        cout<<ar[1].ans<<endl;
    }
}
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

vi edg[N];
int du[N],L[N],R[N],dfn_cnt,br_cnt;
int n,m;
void dfs(int u){
    L[u]=++dfn_cnt;
    for(auto v:edg[u]){
        dfs(v);
    }
    R[u]=dfn_cnt;
}
struct A{
    int l,r,h,op;
}br[N];
ll sum[N<<2],lazy[N<<2];
void pushup(int o,int l,int r){
    if(lazy[o])sum[o]=r-l+1;
    else if(l==r){
        sum[o]=0;
    }
    else{
        sum[o]=sum[lo]+sum[ro];
    }
}
void add(int ql,int qr,int v,int o=1,int l=1,int r=dfn_cnt){
    if(ql<=l&&r<=qr){
        lazy[o]+=v;
        pushup(o,l,r);
        return;
    }
    if(ql<=mid)add(ql,qr,v,lo,l,mid);
    if(qr>mid)add(ql,qr,v,ro,mid+1,r);
    pushup(o,l,r);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m;
    vector<string>ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u=i*m+j,v=-1;
            if(ar[i][j]=='U'&&i+2!=n){
                v=u+2*m;
            }
            if(ar[i][j]=='D'&&i-2>=0){
                v=u-2*m;
            }
            if(ar[i][j]=='L'&&j+2!=m){
                v=u+2;
            }
            if(ar[i][j]=='R'&&j-2>=0){
                v=u-2;
            }
            if(~v){
                edg[v].push_back(u);
                du[u]++;
            }
        }
    }
    for(int i=0;i<n*m;i++){
        if(du[i]==0){
            dfs(i);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u=i*m+j,v=-1;
            if(ar[i][j]=='U'){
                v=u+m;
            }
            else if(ar[i][j]=='L'){
                v=u+1;
            }
            if(~v){
                if((i+j)%2)swap(v,u);
                br[br_cnt++]={L[u],R[u],L[v],1};
                br[br_cnt++]={L[u],R[u],R[v]+1,-1};
            }
        }
    }
    sort(br,br+br_cnt,[](A a,A b){
        return a.h<b.h;
    });
    ll ans=0;
    for(int i=0;i<br_cnt;i++){
        if(i){
            ans+=(ll)(br[i].h-br[i-1].h)*(sum[1]);
        }
        add(br[i].l,br[i].r,br[i].op);
    }
    cout<<ans;
}
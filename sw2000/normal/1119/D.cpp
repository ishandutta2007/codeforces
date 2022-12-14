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
template<class T>void Min(T &a,const T b){if(b<a)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#define F(x){x;}
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#define F(x)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=1e5+10,M=200+10;
const ll mod=998244353;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n;cin>>n;
    vl ar(n),d(n);
    for(auto &i:ar)cin>>i;
    sort(ar.begin(),ar.end());
    for(int i=1;i<n;i++){
        d[i]=ar[i]-ar[i-1];
    }
    sort(d.begin(),d.end());
    vl pre(d);
    for(int i=1;i<pre.size();i++)pre[i]+=pre[i-1];
    int q;cin>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        ll len=r-l+1;
        ll ans=len+pre.back();
        int p=upper_bound(d.begin(),d.end(),len)-d.begin();
        ans-=pre.back()-pre[p-1]-len*(n-p);
        cout<<ans<<' ';
    }
}
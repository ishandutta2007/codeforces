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
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=20+10;
const ll mod=998244353;

int n,m;
ll solve(){
    cin>>n>>m;
    vi ar(n);
    vector<pll>br;
    for(auto &i:ar){
        cin>>i;
    }
    sort(ar.begin(),ar.end());
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        auto it=lower_bound(ar.begin(),ar.end(),l);
        if(it==ar.end()||*it>r)br.push_back({l,r});
    }
    sort(br.begin(),br.end());
    int id=0;
    ll f[2]{},lst=-linf;
    for(auto now:ar){
        vector<pll>v;
        while(id!=br.size()&&br[id].fi<=now){
            v.push_back(br[id]);
            id++;
        }
        vector<ll>mi(v.size()+1);
        for(int i=(int)v.size()-1;~i;i--){
            mi[i]=now-v[i].se;
            if(i+1!=v.size())Max(mi[i],mi[i+1]);
        }
        mi[v.size()]=0;

        ll g[2]{min(f[0],f[1])+mi[0],min(f[0],f[1])+mi[0]*2};
        for(int i=0;i<v.size();i++){
            ll d=v[i].fi-lst;
            Min(g[0],mi[i+1]+min(d*2+f[0],d+f[1]));
            Min(g[1],mi[i+1]*2+min(d+f[1],d*2+f[0]));
        }
        lst=now;
        f[0]=g[0],f[1]=g[1];
    }
    ll d=(id==br.size()?0:br.back().fi-ar.back());
    ll ret=min(f[0]+d*2,f[1]+d);
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<(solve())<<endl;
    }
}
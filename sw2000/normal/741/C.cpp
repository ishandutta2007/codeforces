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

int n,c[N];
vi edg[N];
void dfs(int u,int t){
    c[u]=t;
    for(auto v:edg[u])if(!c[v]){
        dfs(v,3-t);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n;
    vector<pii>ar(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        ar[i]={a,b};
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        edg[i*2].push_back(i*2-1);
        edg[i*2-1].push_back(i*2);
    }
    for(int i=1;i<=n*2;i++)if(c[i]==0){
        dfs(i,1);
    }
    for(auto i:ar){
        cout<<c[i.fi]<<' '<<c[i.se]<<endl;
    }
}
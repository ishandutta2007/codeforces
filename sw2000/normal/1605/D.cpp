#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN    "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<"),";Err(x...);}
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
typedef long double ld;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=2e5+10,M=500;
const ll mod=998244353;

int n,c[N],ans[N];
vi edg[N];
void dfs(int u=1,int co=1){
    c[u]=co;
    for(auto v:edg[u]){
        if(!c[v])dfs(v,3-co);
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs();
    vi v[3];
    for(int i=1;i<=n;i++)v[c[i]].push_back(i);

    int tot=n;
    vi u;
    for(int i=n;i;i--){
        u.push_back(i);
        if((i^i-1)>i-1){
            if(v[1].size()<v[2].size()){
                swap(v[1],v[2]);
            }
            for(auto j:u){
                ans[v[1].back()]=j;
                v[1].pop_back();
            }
            u.clear();
        }
    }

    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
        for(int i=1;i<=n;i++){
            edg[i].clear();
            c[i]=0;
        }
    }
}
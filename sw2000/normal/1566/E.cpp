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
typedef pair<double,double>pii;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const double inf=1e18;
const int N=20+10;
const ll mod=998244353;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    auto solve=[&](){
        int n;cin>>n;
        vector<vi>edg(n);
        vector<bool>vis(n);
        int ret=0;
        function<void(int,int)> dfs=[&](int u,int f){
            vis[u]=1;
            for(auto v:edg[u])if(v!=f){
                dfs(v,u);
                if(vis[v]){
                    vis[u]=0;
                }
            }
            if(vis[u]==0)ret--;
            else ret++;
        };
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;u--,v--;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        dfs(0,0);
        if(vis[0]==0)ret++;
        return ret;
    };
    int _;cin>>_;
    while(_--){
        cout<<(solve())<<endl;
    }
}
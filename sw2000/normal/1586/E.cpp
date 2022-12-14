#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"}";Err(x...);}
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
//#define endl '\n'
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
const int N=3e5+10,M=400;
const ll mod=998244353;
int n,m,vis[N],dep[N],du[N],fa[N],cnt;
vi edg[N],e[N];
void dfs(int u){
    vis[u]=1;
    for(auto v:edg[u])if(!vis[v]){
        e[u].push_back(v);
        fa[v]=u;
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
void dfs2(int u){
    K(u,du[u])
    int c=0;
    for(auto v:e[u]){
        c+=du[v];
    }
    if(du[u]&&c)c--;
    cnt+=(c+1)/2;
    for(auto v:e[u])dfs2(v);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1);
    K(vi(dep+1,dep+1+n))
    int q;cin>>q;
    vector<vi>ans(q);
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        vi va,vb;
        while(dep[a]>dep[b]){
            va.push_back(a);
            du[a]++;
            a=fa[a];
        }
        while(dep[b]>dep[a]){
            vb.push_back(b);
            du[b]++;
            b=fa[b];
        }
        while(a!=b){
            va.push_back(a);
            du[a]++;
            a=fa[a];
            vb.push_back(b);
            du[b]++;
            b=fa[b];
        }
        va.push_back(a);
        for(int i=(int)vb.size()-1;~i;i--){
            va.push_back(vb[i]);
        }
        ans[i]=va;
        K(vi(du+1,du+n+1))
    }
    bool f=0;
    for(int i=2;i<=n;i++){
        du[i]%=2;
        if(du[i])f=1;
    }
    if(!f){
        cout<<"YES"<<endl;
        for(auto i:ans){
            cout<<i.size()<<endl;
            for(auto j:i)cout<<j<<' ';
            cout<<endl;
        }
        return 0;
    }
    cout<<"NO"<<endl;
    dfs2(1);
    cout<<cnt;
}
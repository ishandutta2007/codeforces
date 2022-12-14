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
const int N=2e5+10;
const ll mod=998244353;

int n,m,m1[N],m2[N];
vi e1[N],e2[N];
set<int>s;
bool vis[N];
void dfs(int u){
    s.insert(u);
    vis[u]=1;
    for(auto v:e1[u]){
        if(s.count(v)){cout<<-1;exit(0);}
        if(!vis[v])dfs(v);
        Min(m1[u],m1[v]);
    }
    s.erase(u);
}
void dfs2(int u){
    vis[u]=1;
    for(auto v:e2[u]){
        if(!vis[v])dfs2(v);
        Min(m2[u],m2[v]);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m;
    iota(m1+1,m1+1+n,1);
    iota(m2+1,m2+1+n,1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)if(!vis[i])dfs2(i);
    int ans=0;
    string s;
    for(int i=1;i<=n;i++){
        if(m1[i]==m2[i]&&m1[i]==i)ans++,s+='A';
        else s+="E";
    }
    cout<<ans<<endl<<s;
}
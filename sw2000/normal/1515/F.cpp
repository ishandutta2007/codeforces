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
const int N=2000+10,M=400;
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,m,x;cin>>n>>m>>x;
    vl ar(n);
    for(auto &i:ar)cin>>i;
    vector<pii>br(m);
    vector<vi>edg(n);
    vi father(n);iota(father.begin(),father.end(),0);
    function<int(int)>ff=[&](int a){return father[a]==a?a:father[a]=ff(father[a]);};
    for(auto &i:br){
        cin>>i.fi>>i.se,i.fi--,i.se--;
        int fa=ff(i.fi),fb=ff(i.se);
        if(fa!=fb){
            edg[i.fi].push_back(i.se);
            edg[i.se].push_back(i.fi);
            father[fa]=fb;
        }
    }
    vector<pii>ans;
    iota(father.begin(),father.end(),0);
    function<void(int,int)>dfs=[&](int u,int f){
        for(auto v:edg[u])if(v!=f){
            dfs(v,u);
            if(ar[v]>=x){
                father[v]=u;
                ar[u]+=ar[v]-x;
                ar[v]=0;
                ans.push_back({u,v});
            }
        }
    };dfs(0,0);
    function<void(int,int)>dfs2=[&](int u,int f){
        for(auto v:edg[u])if(v!=f){
            int fa=ff(v);
            if(fa!=0){
                if(ar[0]+ar[fa]<x){
                    cout<<"NO"<<endl;
                    exit(0);
                }
                ar[0]+=ar[fa]-x;
                ar[fa]=0;
                father[fa]=0;
                ans.push_back({u,v});
            }
            dfs2(v,u);
        }
    };dfs2(0,0);
    map<pii,int>mp;
    for(int i=0;i<m;i++){
        mp[br[i]]=i;
        mp[{br[i].se,br[i].fi}]=i;
    }
    cout<<"YES"<<endl;
    for(auto i:ans){
        cout<<mp[i]+1<<endl;
    }
}
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
const int N=5e5+10,M=500;
const ll mod=1e9+7;

string color[]{"white","yellow","green","blue","red","orange"};
ll f[N];
int ceng(ll a){
    int ret=0;
    while(a){
        ret++;
        a/=2;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    f[1]=1;
    int n;cin>>n;
    for(int i=2;i<=60;i++){
        f[i]=(f[i-1]*f[i-1])%mod*16%mod;
    }
    map<string,int>mp;
    for(int i=0;i<6;i++)mp[color[i]]=i;
    int m;cin>>m;
    map<ll,array<ll,6>>g;
    for(int i=0;i<m;i++){
        ll id;string s;cin>>id>>s;
        g[id][mp[s]]=1;
    }
    vl tmp;
    for(auto i:g){
        ll a=i.fi/2;
        while(a){
            tmp.push_back(a);
            a/=2;
        }
    }
    for(auto i:tmp){
        if(g.find(i)==g.end()){
            for(int j=0;j<6;j++){
                g[i][j]=1;
            }
        }
    }
    for(auto it=g.end();it!=g.begin();){
        it--;
        ll o=it->fi,d=ceng(o);
        if(d==n)continue;
        array<ll,6>left{},right{};
        if(g.find(lo)==g.end()){
            for(int j=0;j<6;j++)left[j]=f[n-d];
        }
        else left=g[lo];
        if(g.find(ro)==g.end()){
            for(int j=0;j<6;j++)right[j]=f[n-d];
        }
        else right=g[ro];
        for(int i=0;i<6;i++)if(it->se[i]){
            ll a=0;
            for(int j=0;j<6;j++)if(j!=i&&(j^1)!=i){
                for(int k=0;k<6;k++)if(k!=i&&(k^1)!=i){
                    (a+=(left[j]*right[k])%mod)%=mod;
                }
            }
            it->se[i]=a;
        }
    }
    ll ans=0;
    for(int i=0;i<6;i++)(ans+=g[1][i])%=mod;
    cout<<ans;
}
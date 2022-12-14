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
const int N=2e5+10,M=200+10;
const ll mod=1e9+97;

int n,m,p;
ll pm(ll a,ll b){
    ll ret=1;
    for(;b;b>>=1,a=a*a%p)if(b&1)ret=ret*a%p;
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m>>p;
    int elu=p-1,x=elu;
    vi ar(n);
    for(auto &i:ar)cin>>i;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        x=__gcd(a,x);
    }
    vi fac;
    for(int i=1;i*i<elu;i++){
        if(elu%i==0){
            fac.push_back(i);
            if(i*i!=elu)fac.push_back(elu/i);
        }
    }
    sort(fac.begin(),fac.end());
    vector<int>vis(fac.size());
    for(auto i:ar){
        for(int j=0;j<fac.size();j++){
            if(pm(i,fac[j]*x)==1){
                vis[vis.size()-j-1]=1;
                break;
            }
        }
    }
    for(int i=0;i<vis.size();i++)if(vis[i]){
        for(int j=i+1;j<vis.size();j++){
            if(fac[j]%fac[i]==0)vis[j]=1;
        }
    }
    for(int i=vis.size()-1;~i;i--)if(vis[i]){
        vis[i]=elu/fac[i];
        for(int j=i+1;j<vis.size();j++){
            if(fac[j]%fac[i]==0){
                vis[i]-=vis[j];
            }
        }
    }
    int ans=0;
    for(auto i:vis)ans+=i;
    cout<<ans;
}
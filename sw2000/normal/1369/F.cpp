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
const int N=100+10;
const ll mod=998244353;

bool ok(ll a,ll b){
    while(1){
        if(b%2)return a%2^1;
        if(a>b/2)return a%2;
        if(a>b/4)return 1;
        b/=4;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n;cin>>n;
    vl ar(n),br(n);
    for(int i=0;i<n;i++){
        cin>>ar[i]>>br[i];
    }
    vector<vi>f(n,vi(2));
    for(int i=0;i<n;i++){
        f[i][0]=ok(ar[i],br[i]);
        if(ar[i]*2>br[i])f[i][1]=1;
        else f[i][1]=ok(ar[i],br[i]/2);
    }
    K(f)

    bool res=1;
    for(int i=n-1;~i;i--){
        if(res==0){
            res=f[i][1]^1;
        }
        else{
            res=f[i][0]^1;
        }
        K(res)
    }
    cout<<(res^1)<<' ';
    res=0;
    for(int i=n-1;~i;i--){
        if(res==0){
            res=f[i][1]^1;
        }
        else{
            res=f[i][0]^1;
        }
    }
    cout<<(res^1)<<' ';
}
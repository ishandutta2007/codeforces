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
const ll mod=1e9+7;

ll pm(ll a,ll b){
    ll ret=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ret=ret*a%mod;
    return ret;
}
ll fac[N],rev[N];
ll C(int a,int b){
    return fac[a]*rev[b]%mod*rev[a-b]%mod;
}
int solve(){
    ll n,l,r;cin>>n>>l>>r;
    l=1-l,r=r-n;
    if(l>r)swap(l,r);
    ll ret=2*C(n,n/2)*l%mod;
    for(int i=l+1;i<=r;i++){
        int a=i-l;
        if(a>(n+1)/2)break;
        ret+=C(n-a,n/2);
        if(a<=n/2)ret+=C(n-a,(n+1)/2);
    }
    for(int i=r+1;;i++){
        int a=i-l,b=i-r;
        if(a+b>n||a>(n+1)/2)break;
        ret+=C(n-a-b,n/2-a);
        if((n+1)/2-a>=0)ret+=C(n-a-b,(n+1)/2-a);
    }
    ret%=mod;
    if(n%2==0)ret=ret*rev[2]%mod;
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    fac[0]=rev[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    rev[N-1]=pm(fac[N-1],mod-2);
    for(int i=N-2;i;i--)rev[i]=rev[i+1]*(i+1)%mod;
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}
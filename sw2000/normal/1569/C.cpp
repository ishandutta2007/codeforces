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
#define mid ((l+r)/2)
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
const int N=400+10,M=500;
const ll mod=998244353;
const double eps=1e-8;
double sgn(double x){return x<=-eps?-1:(x<eps?0:1);}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    auto solve=[&](){
        int n;cin>>n;
        vi ar(n);
        int ma=0;
        for(auto &i:ar){
            cin>>i;
            Max(ma,i);
        }
        int cnt=0;
        for(auto i:ar)if(ma==i)cnt++;
        if(cnt>1){
            ll ret=1;
            for(int i=1;i<=n;i++)(ret*=i)%=mod;
            return ret;
        }
        cnt=0;
        for(auto i:ar)if(i==ma-1)cnt++;
        if(!cnt)return 0ll;
        ll ret=1;
        for(int i=1;i<=cnt;i++)(ret*=i)%=mod;
        (ret*=cnt)%=mod;
        for(int i=cnt+2;i<=n;i++)(ret*=i)%=mod;
        return ret;
    };
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}
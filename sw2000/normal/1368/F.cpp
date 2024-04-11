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
const int N=100+10;
const ll mod=998244353;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int n;cin>>n;
    if(n<4){cout<<0;return 0;}
    int k,ma=0;
    for(int i=2;i<n;i++){
        int a=n-((n-1)/i+1)-(i-1);
        if(a>ma){
            ma=a;
            k=i;
        }
    }
    K(k)
    vector<bool>vis(n),goal(n);
    for(int i=1;i<n;i+=k){
        for(int j=0;j<k-1;j++){
            goal[i+j]=1;
        }
    }
    while(1){
        vi v;
        for(int i=0;i<n;i++){
            if(goal[i]^vis[i]){
                v.push_back(i);
            }
        }
        if(v.size()<k)break;
        v.resize(k);
        for(auto i:v)vis[i]=1;
        cout<<k;
        for(auto i:v)cout<<' '<<i+1;
        cout<<endl;

        int p;cin>>p;p--;
        for(int i=0;i<k;i++){
            vis[p]=0;
            p=(p+1)%n;
        }
    }
    cout<<0;
}
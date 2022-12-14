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
const int N=1e3+10,M=500;
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n;cin>>n;
    vi ar(n);
    for(auto &i:ar)cin>>i;
    vi rk(n);iota(rk.begin(),rk.end(),0);
    sort(rk.begin(),rk.end(),[&](int a,int b){
        return ar[a]<ar[b];
    });
    vi id(n);
    for(int i=0;i<n;i++)id[rk[i]]=i;
    vector<vector<bool>>ans(n+1,vector<bool>(n,0));
    for(int i=0;i<n;i++){
        ans[id[i]][i]=1;
        ar[i]--;
        for(int j=0;ar[i]&&j<id[i];j++,ar[i]--)ans[j][i]=1;
        for(int j=id[i]+2;ar[i]&&j<n+1;j++,ar[i]--)ans[j][i]=1;
    }
    bool f=1;
    for(int i=0;i<n;i++)if(ans[n][i])f=0;
    if(f)ans.pop_back();
    cout<<ans.size()<<endl;
    for(auto i:ans){
        for(auto j:i)cout<<j;
        cout<<endl;
    }
}
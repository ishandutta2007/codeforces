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
const int N=1e6+10,M=500;
const ll mod=998244353;

ll operator^(pll a,pll b){
    return a.fi*b.se-a.se*b.fi;
}
pll operator-(pll a,pll b){
    return {a.fi-b.fi,a.se-b.se};
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n;cin>>n;
    vector<pll>ar(n);
    for(auto &i:ar)cin>>i.fi>>i.se;
    string s;cin>>s;
    int id=0;
    for(int i=1;i<n;i++)if(ar[i]<ar[id])id=i;
    vector<bool>vis(n);vis[id]=1;
    vi ans{id};
    for(int i=0;i<n-2;i++){
        vi rk;
        for(int j=0;j<n;j++)if(!vis[j]){
            rk.push_back(j);
        }
        sort(rk.begin(),rk.end(),[&](int a,int b){
            return ((ar[a]-ar[id])^(ar[b]-ar[id]))<0;
        });
        id=(s[i]=='L'?rk.back():rk.front());
        ans.push_back(id);
        vis[id]=1;
    }
    for(int i=0;i<n;i++)if(!vis[i])ans.push_back(i);
    for(auto i:ans)cout<<i+1<<' ';
}
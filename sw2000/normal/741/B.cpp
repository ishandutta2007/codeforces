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
const int N=1000+10,M=500;
const ll mod=998244353;

pii operator+(pii a,pii b){
    return {a.fi+b.fi,a.se+b.se};
}
int n,m,w,father[N];
int ff(int a){return father[a]==a?a:father[a]=ff(father[a]);}
pii ar[N];
int ans[N];
vector<pii>v[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    iota(father,father+N,0);
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++)cin>>ar[i].fi;
    for(int i=1;i<=n;i++)cin>>ar[i].se;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        int fa=ff(a),fb=ff(b);
        if(fa!=fb){
            father[fa]=fb;
        }
    }
    for(int i=1;i<=n;i++){
        int fa=ff(i);
        v[fa].push_back(ar[i]);
    }
    for(int i=1;i<=n;i++)if(father[i]==i){
        pii all{};
        for(auto t:v[i])all=all+t;
        v[i].push_back(all);
        int tmp[N]{};
        for(auto t:v[i]){
            for(int j=t.fi;j<=w;j++){
                Max(tmp[j],ans[j-t.fi]+t.se);
            }
        }
        for(int j=0;j<=w;j++)Max(ans[j],tmp[j]);
    }
    cout<<ans[w];
}
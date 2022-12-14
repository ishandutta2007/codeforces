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
const int N=2e5+10,M=400;
const ll mod=998244353;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,m;cin>>n>>m;
    vector<vi>cnt(M);
    for(int i=0;i<M;i++)cnt[i].resize(i);
    vector<pii>ar(n);
    for(auto &i:ar)cin>>i.fi>>i.se;

    vi vis(m);
    vi pos(n);
    int ans=0;
    for(int i=0;i<m;i++){
        int op,k;cin>>op>>k;k--;
        int a=ar[k].fi,b=ar[k].se,c=a+b;
        int d=op==2?pos[k]:i;
        pos[k]=i;
        int l=(d+a)%c,r=d%c;
        if(op==2)op=-1;

        ans+=vis[i];
        if(c<M){
            for(int j=l;j!=r;j=(j+1)%c){
                cnt[c][j]+=op;
            }
        }
        else{
            for(int j=l;j<m;j+=c){
                vis[j]+=op;
                if(j<=i)ans+=op;
            }
            for(int j=(r<l?r+c:r);j<m;j+=c){
                vis[j]-=op;
                if(j<=i)ans-=op;
            }
        }

        int add=0;
        for(int j=1;j<M;j++)add+=cnt[j][i%j];
        cout<<ans+add<<endl;
    }
}
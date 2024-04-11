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
const int N=100+10,M=400;
const ll mod=998244353;
int n,m,k,p;
ll f[N][N][N];
ll C[N][N];
ll solve(int i,int j,int x){
    if(x>i||x&&j>i)return 0;
    if(~f[i][j][x])return f[i][j][x];
    ll tmp=0;
    for(int a=1;a<=i;a++){
        for(int b=max(0,a+x-i);b<=x&&b<=a;b++){
            tmp+=C[i-1][a-1]*solve(a-1,j-1,b)%p*solve(i-a,j-1,x-b)%p;
        }
    }
    return f[i][j][x]=tmp%p;
}
int main(){
    memset(f,-1,sizeof(f));
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m>>k>>p;
    for(int i=0;i<N;i++)C[i][0]=1%p;
    for(int i=1;i<N;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
    for(int i=0;i<N;i++){
        f[0][i][0]=1;
        for(int j=1;j<N;j++){
            f[0][i][j]=0;
        }
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++)f[i][1][j]=0;
        if(i==1)f[i][1][1]=1;
        else f[i][1][1]=f[i-1][1][1]*i%p;
    }
    cout<<solve(n,m,k);
}
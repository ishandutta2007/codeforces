#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
typedef long long ll;
typedef long double ld;
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

int n,m;
char s[N];
int nxt[17][N];
bool ok(int k){
    for(int i=0;i<m;i++){
        nxt[i][n+1]=inf;
        int cnt=0;
        for(int j=n;j;j--){
            if(s[j]=='?'||s[j]=='a'+i){
                cnt++;
            }
            else cnt=0;
            if(cnt>=k)nxt[i][j]=j+k;
            else nxt[i][j]=nxt[i][j+1];
        }
    }
    vi f(1<<m,inf);
    f[0]=1;
    for(int i=1;i<f.size();i++){
        for(int j=0;j<m;j++)if(i&1<<j){
            Min(f[i],nxt[j][f[i^1<<j]]);
        }
        if(f[i]==inf)return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>m;
    cin>>s+1;
    int l=0,r=n+1;
    while(l+1<r){
        if(ok(mid))l=mid;
        else r=mid;
    }
    cout<<l;
}
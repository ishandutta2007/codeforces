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
template<class T>void Min(T &a,const T b){if(b<a)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#define F(x){x;}
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#define F(x)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=1e5+10,M=500+10;
const ll mod=998244353;

int ans[N],two[N];
int n;
vi edg[N];
int f[N];
void dfs(int u,int fa,int d){
    int cnt=0;
    for(auto v:edg[u])if(v!=fa){
        dfs(v,u,d);
        if(f[v]==1){
            cnt++;
        }
    }
    if(cnt%d==0)f[u]=1;
    else if(cnt%d<d-1)f[u]=-1;
    else if(cnt%d==d-1)f[u]=0;
}
bool ok(int d){
    for(int i=1;i<=n;i++)f[i]=0;
    dfs(1,1,d);
    K(vi(f+1,f+1+n),d)
    if(f[1]==0)return 0;
    for(int i=1;i<=n;i++)if(f[i]==-1)return 0;
    return 1;
}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    for(int i=2;i<=n;i++)if((n-1)%i==0){
        ans[i]=ok(i);
    }
    for(int i=n;i;i--){
        for(int j=i*2;j<=n;j+=i){
            ans[i]-=ans[j];
        }
    }
    ans[1]=(ans[1]+two[n-1]+mod)%mod;
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    two[0]=1;
    for(int i=1;i<N;i++)two[i]=two[i-1]*2%mod;
    int _;cin>>_;
    while(_--){
        solve();
        for(int i=1;i<=n;i++){
            edg[i].clear();
            ans[i]=0;
        }
    }
}
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
const ll mod=998244353;

vi prm,mu(N),phi(N);
bitset<N>vis;
void prepare(){
    mu[1]=phi[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i])prm.push_back(i),mu[i]=-1,phi[i]=i-1;
        for(auto j:prm)if(i*j>=N)break;else{
            vis[i*j]=1;
            if(i%j){
                mu[i*j]=-mu[i];
                phi[i*j]=phi[i]*(j-1);
            }
            else{
                mu[i*j]=0;
                phi[i*j]=phi[i]*j;
                break;
            }
        }
    }
}
int n;
ll ar[N],br[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    prepare();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    for(int i=1;i<=n;i++){
        cin>>br[i];
        if(i==1)br[i]=0;
        br[i]-=ar[i];
    }
    ll ans=0;
    vl v;
    for(int i=1;i<=n;i++){
        for(int j=i*2;j<=n;j+=i){
            br[j]-=br[i];
        }
        if(mu[i])v.push_back(br[i]*mu[i]);
        ans+=abs(br[i]);
    }
    sort(v.begin(),v.end());
    vl pre(v.size()+1);
    for(int i=1;i<pre.size();i++)pre[i]=pre[i-1]+v[i-1];
    int q;cin>>q;
    while(q--){
        ll x;cin>>x;
        int p=lower_bound(v.begin(),v.end(),-x)-v.begin();
        int p0=lower_bound(v.begin(),v.end(),0)-v.begin();
        ll add=(v.size()-p*2)*x+2*(pre[p0]-pre[p]);
        cout<<ans+add<<endl;
    }
}
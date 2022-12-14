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
const int N=1e5+10,M=200+10;
const ll mod=998244353;

struct A{
    ll l,r,h,op;
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,k;cin>>n>>k;
    vl ans(n+1);
    vector<A>ar;
    vl br;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        ar.push_back({x,x+k,y,1});
        ar.push_back({x,x+k,y+k,-1});
        br.push_back(x);
        br.push_back(x+k);
    }
    sort(ar.begin(),ar.end(),[](A a,A b){
        if(a.h!=b.h)return a.h<b.h;
        else return a.op<b.op;
    });
    sort(br.begin(),br.end());
    br.erase(unique(br.begin(),br.end()),br.end());
    vector<pll> cnt(br.size());
    for(auto i:ar){
        int l=lower_bound(br.begin(),br.end(),i.l)-br.begin();
        int r=lower_bound(br.begin(),br.end(),i.r)-br.begin();
        for(int j=l;j<r;j++){
            ans[cnt[j].fi]+=(i.h-cnt[j].se)*(br[j+1]-br[j]);
            cnt[j].fi+=i.op;
            cnt[j].se=i.h;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
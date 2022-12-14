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
const int N=2000+10,M=400;
const ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,m;cin>>n>>m;
    vi ar(n),br(m);
    for(auto &i:ar)cin>>i;
    for(auto &i:br)cin>>i;
    sort(ar.begin(),ar.end());
    sort(br.begin(),br.end());
    if(ar.back()>br.front()){
        cout<<-1;
        return 0;
    }
    ll ans=0;
    for(auto i:ar)ans+=i;
    ans*=m;
    vi need;
    for(int i=n-1;~i;i--){
        for(int j=0;j<m-1;j++){
            need.push_back(ar[i]);
            if(need.size()==m)break;
        }
        if(need.size()==m)break;
    }
    reverse(need.begin(),need.end());
    for(auto i:br){
        if(i!=ar.back()){
            if(need.empty())return cout<<-1,0;
            ans+=i-need.back();
            need.pop_back();
        }
    }
    cout<<ans;
}
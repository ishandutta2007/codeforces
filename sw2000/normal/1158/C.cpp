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

void solve(){
    int n;cin>>n;
    vector<vi>edg(n+1);
    vi nxt(n);
    for(int i=0;i<n;i++){
        cin>>nxt[i];
        if(nxt[i]!=-1){
            nxt[i]--;
            edg[nxt[i]].push_back(i);
        }
    }
    int tot=n;
    vi ar(n,-1);
    for(int i=n;~i;i--){
        if(i!=n&&ar[i]==-1)ar[i]=tot--;
        for(auto j:edg[i]){
            ar[j]=tot--;
        }
    }
    K(ar)
    vector<pii> v{{-inf,n}};
    for(int i=n-1;~i;i--){
        auto it=lower_bound(v.begin(),v.end(),(pii){-ar[i],0});
        it--;
        K(*it)
        if(nxt[i]!=-1&&it->se!=nxt[i]){
            cout<<-1;
            return;
        }
        while(ar[i]>-v.back().fi){
            v.pop_back();
        }
        v.push_back({-ar[i],i});
    }
    for(int i=0;i<n;i++){
        cout<<ar[i]<<' ';
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
        cout<<endl;
    }
}
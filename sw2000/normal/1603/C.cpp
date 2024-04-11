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

int n;
int ar[N];
ll solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ar[i];
    ll ret=0;
    vector<pll>lst{{1,0}};
    for(int i=1;i<=n;i++){
        vector<array<ll,3>>v;
        for(int l=1,r;l<=ar[i];l=r+1){
            int a=ar[i]/l;
            r=ar[i]/a;
            v.push_back({a,a+(ar[i]%l!=0),l});
            v.push_back({a,a+(ar[i]%r!=0),r});
        }
        reverse(v.begin(),v.end());
        int k=0;
        vector<pll>nxt;
        for(auto j:v){
            while(k+1<lst.size()&&lst[k+1].fi<=j[0])k++;
            pll tmp={j[1],lst[k].se+i*(j[2]-1)};
            if(!nxt.empty()&&tmp.fi==nxt.back().fi)Min(nxt.back().se,tmp.se);
            else nxt.push_back(tmp);
        }
        lst=nxt;
        (ret+=nxt.back().se)%=mod;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}
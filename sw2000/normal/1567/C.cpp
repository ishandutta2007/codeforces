#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T, class... A>void Err(T a, A... x){cerr<<a<<','; Err(x...); }
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T, class t,class...A>void Err(T<t>a,A...x){cerr<<"{";for(auto v:a)Err(v);cerr<<"}";Err(x...); }
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid ((l+r)/2)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef vector<int>vi;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    vi cnt(20);
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)cnt[i+j]++;
    auto solve=[&](){
        int n;cin>>n;
        vi ar;
        while(n){
            ar.push_back(n%10);
            n/=10;
        }
        ll ret=0;
        function<void(int)> dfs=[&](int d){
            if(d<2){
                ll a=1;
                for(auto i:ar)a*=cnt[i];
                ret+=a;
                return;
            }
            if(ar[d]){
                ar[d]--;
                ar[d-2]+=10;
                dfs(d-1);
                ar[d]++;
                ar[d-2]-=10;
            }
            dfs(d-1);
        };dfs(ar.size()-1);
        return ret-2;
    };
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}
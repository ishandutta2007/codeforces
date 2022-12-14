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
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=20+10;
const ll mod=1e9+7;

bool solve(){
    string s,t;cin>>s>>t;
    for(int l=0;l<s.size();l++){
        for(int r=l;r<s.size();r++){
            int len=r-l+1;
            if(len<=t.size()&&s.substr(l,len)==t.substr(0,len)){
                string tt=t.substr(len);
                len=tt.size();
                if(r-len>=0){
                    string tmp=s.substr(r-len,len);
                    reverse(tmp.begin(),tmp.end());
                    if(tmp==tt)return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    string s="1234567";
    int _;cin>>_;
    while(_--){
        cout<<(solve()?"YES":"NO")<<endl;
    }
}
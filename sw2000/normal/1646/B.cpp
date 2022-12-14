#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define K(x...){cerr<<"BEGIN    "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<"),";Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
const double eps=1e-8;
int sgn(double a){return a<-eps?-1:(a<eps?0:1);}
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=5e5+10,M=500;
const ll mod=1e9+7;

bool solve(){
	int n;cin>>n;
	vector<ll>ar(n);
	for(auto &i:ar)cin>>i;
	sort(ar.begin(),ar.end());
	ll a=0,b=0;
	for(int i=0;i<(ar.size()+1)/2;i++){
		a+=ar[i];
	}
	for(int i=0;i<(ar.size()-1)/2;i++){
		b+=ar[ar.size()-i-1];
	}
	return a<b;
}
int main(){
	freopen("A.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	int _;cin>>_;
	while(_--){
		cout<<(solve()?"YES":"NO")<<endl;
	}
	return 0;
}
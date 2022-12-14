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

struct A{
	int cnt,sum;
}f[N][2];
bool operator<(A a,A b){
	if(a.cnt<b.cnt)return 1;
	else if(a.cnt>b.cnt)return 0;
	else return a.sum>b.sum;
}
A operator+(A a,A b){
	return {a.cnt+b.cnt,a.sum+b.sum};
}

vector<int>edg[N];
void dfs(int u=1,int fa=0){
	for(auto v:edg[u])if(v!=fa){
		dfs(v,u);
		f[u][1]=f[u][1]+f[v][0];
		f[u][0]=f[u][0]+max(f[v][0],f[v][1]);
	}
	f[u][1].cnt++;
	f[u][1].sum+=edg[u].size();
	f[u][0].sum++;
}
int ans[N];
void dfs2(int u=1,int fa=0,bool allcan=1){
	ans[u]=1;
	bool nxt=1;
	if(allcan&&f[u][0]<f[u][1]){
		ans[u]=edg[u].size();
		nxt=0;
	}
	for(auto v:edg[u])if(v!=fa){
		dfs2(v,u,nxt);
	}
}
int main(){
	freopen("A.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		edg[u].push_back(v);
		edg[v].push_back(u);
	}
	if(n==2){
		cout<<"2 2\n1 1";
		return 0;
	}
	dfs();
	cout<<max(f[1][0],f[1][1]).cnt<<' '<<max(f[1][0],f[1][1]).sum<<endl;
	dfs2();
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=100050;
vector<int> E[N];
map<int,bool> con[N];
int n,m,h,t;
bool was[N];
void Solve(int u,int v){
	vector<int> head,tail;
	for(int i:E[u]){
		if(i!=v&&!con[v][i]){
			if(head.size()<h)head.pb(i);
		}
	}
	for(int i:E[u]){
		if(i!=v&&con[v][i]){
			if(head.size()<h)head.pb(i),was[i]=true;
		}
	}
	for(int i:E[v]){
		if(i!=u&&!was[i]){
			if(tail.size()<t)tail.pb(i);
		}
	}
	printf("YES\n");
	printf("%i %i\n",u,v);
	for(int i:head)printf("%i ",i);printf("\n");
	for(int i:tail)printf("%i ",i);printf("\n");
	exit(0);
}
void Try(int u,int v){
	int A=E[u].size()-1;
	int B=E[v].size()-1;
	if(A>=h+t&&B>=h+t)Solve(u,v);
	if(A<h||B<t)return;
	int cntl=0,cntr=0,cntm=0;
	if(A<B){
		for(int i:E[u]){
			if(i!=v&&!con[v][i]){
				cntl++;
			}else if(i!=v)cntm++;
		}
		cntr=B-cntm;
	}else{
		for(int i:E[v]){
			if(i!=u&&!con[u][i]){
				cntr++;
			}else if(i!=u)cntm++;
		}
		cntl=A-cntm;
	}
	if(cntl+cntm+cntr>=h+t)Solve(u,v);
}
int main(){
	rd(n,m,h,t);
	vector<pii> edges;
	for(int i=1;i<=m;i++){
		int u,v;
		rd(u,v);
		edges.pb({u,v});
		E[u].pb(v);
		E[v].pb(u);
		con[u][v]=con[v][u]=true;
	}
	for(auto e:edges){
		int u,v;tie(u,v)=e;
		Try(u,v);
		Try(v,u);
	}
	printf("NO\n");
	return 0;
}
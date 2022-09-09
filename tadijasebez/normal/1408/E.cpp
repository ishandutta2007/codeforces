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

struct DSU{
	vector<int> p;
	DSU(){}
	void init(int n){p.clear();p.resize(n+1);}
	int Find(int x){return p[x]?p[x]=Find(p[x]):x;}
	void Union(int x,int y){if(Find(x)!=Find(y))p[Find(x)]=Find(y);}
	bool Con(int x,int y){return Find(x)==Find(y);}
}G;
const int N=200050;
int a[N],b[N];
int main(){
	int n,m;
	rd(m,n);
	G.init(n+m);
	ra(a,m);
	ra(b,n);
	vector<array<int,3>> edges;
	ll sum=0;
	for(int i=1;i<=m;i++){
		int s=ri();
		while(s--){
			int x=ri();
			edges.pb({a[i]+b[x],i+n,x});
			sum+=a[i]+b[x];
		}
	}
	sort(edges.rbegin(),edges.rend());
	for(auto e:edges){
		if(!G.Con(e[1],e[2])){
			sum-=e[0];
			G.Union(e[1],e[2]);
		}
	}
	printf("%lld\n",sum);
	return 0;
}
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
};

const int N=200050;
const int L=20;
vector<pii> E[N];
int par[N][L],mx[N][L],dep[N];
void DFS(int u,int p,int w){
	par[u][0]=p;
	mx[u][0]=w;
	dep[u]=dep[p]+1;
	for(int i=1;i<L;i++){
		par[u][i]=par[par[u][i-1]][i-1];
		mx[u][i]=max(mx[u][i-1],mx[par[u][i-1]][i-1]);
	}
	for(auto e:E[u])if(e.first!=p)DFS(e.first,u,e.second);
}
int Get(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int mx=0;
	for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])ckmx(mx,::mx[u][i]),u=par[u][i];
	for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])ckmx(mx,::mx[u][i]),ckmx(mx,::mx[v][i]),u=par[u][i],v=par[v][i];
	if(u!=v)ckmx(mx,::mx[u][0]),ckmx(mx,::mx[v][0]);
	return mx;
}
DSU DS;
int main(){
	for(int t=ri();t--;){
		int n=ri(),m=ri(),k=ri();
		vector<array<int,4>> edges;
		for(int i=1;i<=m;i++){
			int u,v,w;
			rd(u,v,w);
			int val=w>k?w-k:0;
			edges.pb({val,u,v,w});
		}
		sort(edges.begin(),edges.end());
		DS.init(n);
		for(int i=1;i<=n;i++)E[i].clear();
		ll mst=0;
		for(auto e:edges){
			int u=e[1],v=e[2];
			if(!DS.Con(u,v)){
				DS.Union(u,v);
				mst+=e[0];
				E[u].pb({v,e[0]});
				E[v].pb({u,e[0]});
			}
		}
		DFS(1,0,0);
		ll ans=9e18;
		for(auto e:edges){
			int mx=Get(e[1],e[2]);
			ckmn(ans,mst-mx+abs(k-e[3]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
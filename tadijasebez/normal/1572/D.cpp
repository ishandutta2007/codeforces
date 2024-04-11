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

const int N=1<<20;
int a[N],n,k,s,t;
int idx[N],tsz;

const int M=4*20*205;
const int inf=1e9+7;
struct Edge{int u,v,f,c,w;};
vector<Edge> edges;
vector<int> G[M];
void AddEdge(int u,int v,int c,int w){
	G[u].pb(edges.size());edges.pb((Edge){u,v,0,c,w});
	G[v].pb(edges.size());edges.pb((Edge){v,u,0,0,-w});
}
int dist[M],go[M];
bool in[M];
bool BFS(){
	for(int i=1;i<=tsz;i++){
		dist[i]=inf;
		in[i]=false;
	}
	queue<int> q;
	q.push(s);dist[s]=0;in[s]=true;
	while(q.size()){
		int u=q.front();
		q.pop();
		in[u]=false;
		for(int e:G[u]){
			int v=edges[e].v;
			int c=edges[e].c-edges[e].f;
			int w=edges[e].w;
			if(c>0&&dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				go[v]=e;
				if(!in[v]){
					q.push(v);
					in[v]=true;
				}
			}
		}
	}
	return dist[t]!=inf;
}
int MCMF(int k){
	int ans=0;
	while(k--&&BFS()){
		ans+=dist[t];
		for(int i=t;i!=s;i=edges[go[i]].u){
			edges[go[i]].f++;
			edges[go[i]^1].f--;
		}
	}
	return ans;
}
int main(){
	rd(n,k);
	ra(a,1<<n,0);
	vector<pair<int,pii>> edges;
	for(int i=0;i<(1<<n);i++)if(__builtin_popcount(i)%2==0){
		for(int j=0;j<n;j++){
			edges.pb({a[i]+a[i^(1<<j)],{i,i^(1<<j)}});
		}
	}
	sort(edges.rbegin(),edges.rend());
	int sz=min(2*n*k,(int)edges.size());
	s=++tsz;
	t=++tsz;
	for(int i=0;i<sz;i++){
		int u,v;tie(u,v)=edges[i].second;
		if(!idx[u]){
			idx[u]=++tsz;
			AddEdge(s,idx[u],1,-a[u]);
		}
		if(!idx[v]){
			idx[v]=++tsz;
			AddEdge(idx[v],t,1,-a[v]);
		}
		AddEdge(idx[u],idx[v],1,0);
	}
	printf("%i\n",-MCMF(k));
	return 0;
}
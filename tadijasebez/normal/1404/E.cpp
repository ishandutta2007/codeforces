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

template<int NSZ,int ESZ,typename C,C inf> struct Dinic{
	struct Edge{
		int v,go;C c;
		Edge(int _v,C _c,int _go):v(_v),c(_c),go(_go){}
		Edge(){}
	};
	Edge edges[ESZ*2];
	int G[NSZ],ptr[NSZ];
	int dist[NSZ],q[NSZ],ql,qr;
	int s,t,n,xb;
	void init(int _n){
		n=_n;xb=ql=qr=0;
		for(int i=0;i<=n;i++)G[i]=-1;
	}
	Dinic(int _n){init(_n);}
	Dinic(){}
	void AddEdge(int u,int v,C c){
		edges[xb]=Edge(v,c,G[u]);G[u]=xb++;
		edges[xb]=Edge(u,0,G[v]);G[v]=xb++;
	}
	C DFS(int u,C flow){
		if(u==t)return flow;
		if(dist[u]>=dist[t])return 0;
		C ans=0;
		for(int &e=ptr[u];e!=-1;e=edges[e].go){
			if(edges[e].c<0||dist[edges[e].v]!=dist[u]+1)continue;
			C cut=DFS(edges[e].v,min(flow-ans,edges[e].c));
			ans+=cut;
			edges[e].c-=cut;
			edges[e^1].c+=cut;
			if(flow==ans)break;
		}
		return ans;
	}
	bool BFS(){
		for(int i=0;i<=n;++i)dist[i]=-1,ptr[i]=G[i];
		dist[s]=0;ql=qr=0;q[qr++]=s;
		while(ql!=qr){
			int u=q[ql++];
			for(int e=G[u];e!=-1;e=edges[e].go){
				if(edges[e].c>0&&dist[edges[e].v]==-1){
					dist[edges[e].v]=dist[u]+1;
					q[qr++]=edges[e].v;
				}
			}
		}
		return dist[t]!=-1;
	}
	C MaxFlow(int _s,int _t){
		s=_s;t=_t;
		C Flow=0;
		while(BFS())Flow+=DFS(s,inf);
		return Flow;
	}
	vector<bool> vis;
	void REC(int u){vis[u]=1;for(int e=G[u];e!=-1;e=edges[e].go)if(edges[e].c>0&&!vis[edges[e].v])REC(edges[e].v);}
	vector<bool> MinCut(){
		vis.assign(n+1,false);
		REC(s);
		return vis;
	}
};

const int inf=1e9+7;
const int N=205;
char base[N][N];
int id1[N][N],id2[N][N],tot;
int main(){
	int n,m;rd(n,m);
	for(int i=1;i<=n;i++)rd(base[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(base[i][j]=='#'){
			if(base[i+1][j]=='#')id1[i][j]=++tot;
			if(base[i][j+1]=='#')id2[i][j]=++tot;
		}
	}
	int s=++tot,t=++tot;
	auto idx1=[&](int i,int j){return id1[i][j];};
	auto idx2=[&](int i,int j){return id2[i][j];};
	Dinic<N*N*2,N*N*6,int,inf> Flow(t);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(base[i][j]=='#'){
			cnt++;
			if(base[i+1][j]=='#'&&base[i][j+1]=='#')Flow.AddEdge(idx1(i,j),idx2(i,j),1);
			if(base[i-1][j]=='#'&&base[i][j+1]=='#')Flow.AddEdge(idx1(i-1,j),idx2(i,j),1);
			if(base[i+1][j]=='#'&&base[i][j-1]=='#')Flow.AddEdge(idx1(i,j),idx2(i,j-1),1);
			if(base[i-1][j]=='#'&&base[i][j-1]=='#')Flow.AddEdge(idx1(i-1,j),idx2(i,j-1),1);
			if(base[i+1][j]=='#')Flow.AddEdge(s,idx1(i,j),1),cnt--;
			if(base[i][j+1]=='#')Flow.AddEdge(idx2(i,j),t,1),cnt--;
		}
	}
	printf("%i\n",cnt+Flow.MaxFlow(s,t));
	return 0;
}
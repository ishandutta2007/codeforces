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

const int N=105;

char same[N][N][N];

void ChainEdge(vector<int> nodes,int&u,int&v){
	//TODO
}

void FindEdge(int n,int&u,int&v){
	vector<int> nodes;
	for(int i=1;i<=n;i++)
		nodes.pb(i);
	while(nodes.size()>2){
		bool ok=false;
		for(int i:nodes){
			for(int j:nodes){
				if(i<j){
					vector<int> nxt;
					for(int z:nodes){
						if(same[i][j][z]=='1'){
							nxt.pb(z);
						}
					}
					if(nxt.size()>1){
						nodes=nxt;
						ok=true;
						break;
					}
				}
			}
			if(ok)break;
		}
		if(!ok){//chain
			ChainEdge(nodes,u,v);
			return;
		}
	}
	u=nodes[0];
	v=nodes[1];
}

vector<int> E[N];
vector<pii> edges;
int ecnt;
void AddEdge(int u,int v){
	ecnt++;
	E[u].pb(v);
	E[v].pb(u);
	edges.pb({u,v});
}
bool done[N];
void Go(int u,int p,int n){
	for(int i=1;i<=n;i++)if(!done[i]){
		int a=i,b=p;
		if(a>b)swap(a,b);
		if(same[a][b][u]=='1'){
			AddEdge(u,i);
			done[i]=true;
			Go(i,u,n);
		}
	}
}
void FindGraph(int n,int u,int v){
	done[u]=true;
	done[v]=true;
	AddEdge(u,v);
	Go(u,v,n);
	Go(v,u,n);
}

int dist[N][N];
void DFS(int u,int p,int from){
	if(p==0)dist[from][u]=0;
	else dist[from][u]=dist[from][p]+1;
	for(int v:E[u])if(v!=p)DFS(v,u,from);
}
bool Check(int n){
	if(ecnt!=n-1)return false;
	for(int i=1;i<=n;i++){
		DFS(i,0,i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=1;z<=n;z++){
				char ok=dist[z][i]==dist[z][j]?'1':'0';
				if(ok!=same[i][j][z])return false;
			}
		}
	}
	return true;
}

bool Try(int u,int v,int n){
	edges.clear();
	for(int i=1;i<=n;i++){
		E[i].clear();
		done[i]=false;
	}

	ecnt=0;
	FindGraph(n,u,v);
	if(!Check(n)){
		return false;
	}else{
		printf("Yes\n");
		for(pii e:edges)printf("%i %i\n",e.first,e.second);
		return true;
	}
}

void Run(){
	int n=ri();
	edges.clear();
	for(int i=1;i<=n;i++){
		E[i].clear();
		done[i]=false;
		for(int j=i+1;j<=n;j++){
			scanf("%s",same[i][j]+1);
		}
	}
	for(int i=2;i<=n;i++){
		if(Try(1,i,n))return;
	}
	printf("No\n");
	/*int u=0,v=0;
	ecnt=0;
	FindEdge(n,u,v);
	if(u==0){
		printf("???\n");
		return;
	}
	FindGraph(n,u,v);
	if(!Check(n)){
		printf("No\n");
	}else{
		printf("Yes\n");
		for(pii e:edges)printf("%i %i\n",e.first,e.second);
	}*/
}

int main(){
	int t=ri();
	while(t--)Run();
	return 0;
}
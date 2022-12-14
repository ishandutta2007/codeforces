#include<cstdio>
#include<vector>
#include<utility>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;

struct edge{
	int to;
	long long cost;
	edge(){}
	edge(int a,long long b):to(a),cost(b){}
};

vector<edge> G[2020];

int req[2020][2020];
long long dis[2020][2020];
int N;

PP pps[2020*2020];
int M;

struct UnionFind{
	int par[2020];
	void init(int N){
		for(int i=0;i<N;i++) par[i]=i;
	}
	int find(int v){
		if(v==par[v]) return v;
		return par[v]=find(par[v]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		par[x]=y;
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
};

UnionFind uf;

queue<int> que;
void bfs(int v){
	for(int i=0;i<N;i++) dis[v][i]=-1;
	dis[v][v]=0;
	que.push(v);
	while(!que.empty()){
		int cur=que.front();
		que.pop();
		for(int i=0;i<G[cur].size();i++){
			int nv=G[cur][i].to;
			long long nd=dis[v][cur]+G[cur][i].cost;
			if(dis[v][nv]!=-1) continue;
			dis[v][nv]=nd;
			que.push(nv);
		}
	}
}

void answer(bool flg){
	if(flg) printf("YES\n");
	else printf("NO\n");
	exit(0);
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++){
		scanf("%d",&req[i][j]);
	}
	for(int i=0;i<N;i++) for(int j=0;j<N;j++){
		if(i==j){
			if(req[i][j]!=0) answer(false);
		}else{
			if(req[i][j]!=req[j][i]) answer(false);
			if(req[i][j]==0) answer(false);
		}
	}
	M=0;
	for(int i=0;i<N;i++) for(int j=i+1;j<N;j++){
		PP pp=PP(req[i][j],P(i,j));
		pps[M++]=pp;
	}
	sort(pps,pps+M);
	uf.init(N);
	for(int i=0;i<M;i++){
		PP pp=pps[i];
		int d=pp.first;
		int u=pp.second.first;
		int v=pp.second.second;
		if(uf.same(u,v)) continue;
		uf.unite(u,v);
		G[u].push_back(edge(v,d));
		G[v].push_back(edge(u,d));
	}
	for(int i=0;i<N;i++){
		bfs(i);
	}
	for(int i=0;i<N;i++) for(int j=0;j<N;j++){
		if(req[i][j]!=dis[i][j]) answer(false);
	}
	answer(true);
	return 0;
}
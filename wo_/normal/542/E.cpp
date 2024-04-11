#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int m,head[1010],to[200200],nxt[200200];

void init_edge(){
	for(int i=0;i<1010;i++){
		head[i]=-1;
	}
	m=0;
}

void add_edge(int u,int v){
	nxt[m]=head[u];to[m]=v;head[u]=m;m++;
	nxt[m]=head[v];to[m]=u;head[v]=m;m++;
}

int dis[1010];
int N,M;

int solve(int v){
	for(int i=0;i<N;i++) dis[i]=-1;
	dis[v]=0;
	queue<int> que;
	que.push(v);
	int res=0;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		int nd=dis[u]+1;
		for(int e=head[u];e!=-1;e=nxt[e]){
			int v=to[e];
			if(dis[v]!=-1&&(dis[v]-nd)%2!=0) return -1;
			if(dis[v]!=-1&&dis[v]<=nd) continue;
			dis[v]=nd;
			que.push(v);
			res=max(res,nd);
		}
	}
	return res;
}

struct UnionFind{
	int par[1010];
	void init(int N){
		for(int i=0;i<N;i++) par[i]=i;
	}
	int find(int v){
		if(v==par[v]) return v;
		return par[v]=find(par[v]);
	}
	void unite(int u,int v){
		u=find(u);v=find(v);
		if(u==v) return;
		par[v]=u;
	}
	bool same(int u,int v){
		return find(u)==find(v);
	}
};

UnionFind uf;

int res[1010];

int main(){
	scanf("%d%d",&N,&M);
	init_edge();
	uf.init(N);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		add_edge(u,v);
		uf.unite(u,v);
	}
	for(int i=0;i<N;i++){
		int cur=solve(i);
		if(cur==-1){
			printf("-1\n");
			return 0;
		}
		res[uf.find(i)]=max(res[uf.find(i)],cur);
	}
	int ans=0;
	for(int i=0;i<N;i++){
		if(uf.par[i]==i){
			ans+=res[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
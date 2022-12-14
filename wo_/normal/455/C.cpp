#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[300300];

int root[300300];
int dep[300300];
int deepest[300300];

void dfs(int v,int p,int d,int r){
	dep[v]=d;
	root[v]=r;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs(u,v,d+1,r);
	}
	if(deepest[r]==-1||dep[deepest[r]]<dep[v]) deepest[r]=v;
}

struct UnionFind{
	int par[300300];
	int val[300300];
	void init(int N){
		for(int i=0;i<N;i++){
			par[i]=-1;
			val[i]=0;
		}
	}
	int find(int x){
		if(par[x]==-1) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		int a=val[x],b=val[y];
		int nv=max(max(a,b),((a+1)/2+(b+1)/2+1));
		par[y]=x;
		val[x]=nv;
	}
	void setVal(int x,int v){
		x=find(x);
		val[x]=max(val[x],v);
	}
};

UnionFind uf;

int main(){
	int N,M,Q;
	scanf("%d%d%d",&N,&M,&Q);
	uf.init(N);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
		uf.unite(u,v);
	}
	for(int i=0;i<N;i++){
		root[i]=-1;
		deepest[i]=-1;
	}
	for(int i=0;i<N;i++){
		if(root[i]==-1) dfs(i,-1,0,i);
	}
	for(int i=0;i<N;i++){
		if(deepest[i]!=-1){
			int v=deepest[i];
			dfs(v,-1,0,v);
		}
	}
	for(int i=0;i<N;i++){
		uf.setVal(i,dep[i]);
	}
	for(int q=0;q<Q;q++){
		int type;
		scanf("%d",&type);
		if(type==1){
			int x;
			scanf("%d",&x);
			x--;
			x=uf.find(x);
			printf("%d\n",uf.val[x]);
		}
		else{
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			uf.unite(u,v);
		}
	}
	return 0;
}
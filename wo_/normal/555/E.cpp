#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

const int MV=200200,ME=200200;

int m,head[MV],to[ME*2],nxt[ME*2];
int V,E;
int pre_[MV];
int low[MV];
int cmp_id[MV];
vector<int> cmps[MV];
int num_cmp=0;
int c=0;

void init_edge(){
	for(int i=0;i<V;i++) head[i]=-1;
}
void add_edge(int u,int v){
	nxt[m]=head[u];to[m]=v;head[u]=m;m++;
	nxt[m]=head[v];to[m]=u;head[v]=m;m++;
}

void visit(int v,int p,stack<int> &roots,stack<int> &s){
	pre_[v]=c++;
	low[v]=pre_[v];
	s.push(v);
	roots.push(v);
	bool flg=false;
	for(int e=head[v];e!=-1;e=nxt[e]){
		int u=to[e];
		if(u==p&&flg==false){
			flg=true;
			continue;
		}else if(pre_[u]==-1){
			visit(u,v,roots,s);
			low[v]=min(low[v],low[u]);
		}else{
			low[v]=min(low[v],pre_[u]);
			while(pre_[roots.top()]>pre_[u]){
				roots.pop();
			}
		}
	}
	if(v==roots.top()){
		while(true){
			int w=s.top();
			s.pop();
			cmp_id[w]=num_cmp;
			if(w==v) break;
		}
		num_cmp++;
		roots.pop();
	}
}

void dEdgeDecomposition(){
	for(int i=0;i<V;i++) pre_[i]=-1;
	c=0,num_cmp=0;
	stack<int> roots,s;
	for(int v=0;v<V;v++){
		if(pre_[v]==-1){
			visit(v,-1,roots,s);
		}
	}
	for(int i=0;i<V;i++) cmps[i].clear();
	for(int i=0;i<V;i++) cmps[cmp_id[i]].push_back(i);
}

const int LOG_MV=20;

int N;
vector<int> G[MV];
int par[MV][LOG_MV];
int dep[MV];

void get_tree(){
	for(int v=0;v<V;v++){
		for(int e=head[v];e!=-1;e=nxt[e]){
			int u=to[e];
			int nv=cmp_id[v],nu=cmp_id[u];
			if(nv==nu) continue;
			G[nv].push_back(nu);
		}
	}
	N=num_cmp;
}

void dfs(int v,int p,int d){
	par[v][0]=p;
	dep[v]=d;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs(u,v,d+1);
	}
}

void pre_lca(){
	for(int j=1;j<LOG_MV;j++){
		for(int i=0;i<N;i++){
			if(par[i][j-1]==-1) par[i][j]=-1;
			else par[i][j]=par[par[i][j-1]][j-1];
		}
	}
}
int get_lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int dif=dep[u]-dep[v];
	for(int j=0;j<LOG_MV;j++){
		if((dif>>j)&1) u=par[u][j];
	}
	if(u==v) return v;
	for(int j=LOG_MV-1;j>=0;j--){
		if(par[u][j]!=par[v][j]){
			u=par[u][j];
			v=par[v][j];
		}
	}
	if(par[u][0]!=par[v][0]) return -1;//other compo
	return par[v][0];
}

int req[MV][2];

void dfs2(int v,int p){
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs2(u,v);
		req[v][0]+=req[u][0];
		req[v][1]+=req[u][1];
	}
}

int Q;

int main(){
	scanf("%d%d%d",&V,&E,&Q);
	init_edge();
	for(int i=0;i<E;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		add_edge(u,v);
	}
	dEdgeDecomposition();
	get_tree();
	for(int i=0;i<N;i++) par[i][0]=-1;
	for(int i=0;i<N;i++){
		if(par[i][0]==-1) dfs(i,-1,0);
	}
	pre_lca();
//	for(int i=0;i<V;i++) printf("%d ",cmp_id[i]);
//	printf("\n");
	for(int q=0;q<Q;q++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		u=cmp_id[u],v=cmp_id[v];
		if(u==v) continue;
		int lca=get_lca(u,v);
		if(lca==-1){
			printf("No\n");
			return 0;
		}
		req[u][0]++;
		req[lca][0]--;
		req[lca][1]--;
		req[v][1]++;
	}
	for(int i=0;i<N;i++){
		if(par[i][0]==-1) dfs2(i,-1);
	}
	for(int i=0;i<N;i++){
		if(req[i][0]>0&&req[i][1]>0){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
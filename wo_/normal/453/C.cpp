#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[100100];

int req[100100];
int cur[100100];
bool used[100100];

vector<int> ans;

void dfs(int v,int p){
	used[v]=true;
	ans.push_back(v);
	cur[v]^=1;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		if(used[u]) continue;
		dfs(u,v);
		ans.push_back(v);
		cur[v]^=1;
	}
	if(cur[v]!=req[v]&&p>=0){
		ans.push_back(p);
		ans.push_back(v);
		cur[p]^=1;
		cur[v]^=1;
	}
}

struct UnionFind{
	int par[100100];
	void init(int N){
		for(int i=0;i<N;i++) par[i]=-1;
	}
	int find(int v){
		if(par[v]==-1) return v;
		return par[v]=find(par[v]);
	}
	void unite(int u,int v){
		u=find(u),v=find(v);
		if(u==v) return;
		par[u]=v;
	}
};

UnionFind uf;

int cnt[100100];

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	uf.init(N);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
		uf.unite(u,v);
	}
	for(int i=0;i<N;i++) scanf("%d",req+i);
	for(int i=0;i<N;i++){
		if(req[i]==1){
			cnt[uf.find(i)]++;
		}
	}
	int r=-1,c=0;
	for(int i=0;i<N;i++){
		if(cnt[i]!=0){
			c++;
			r=i;
		}
	}
	if(c>=2){
		printf("-1\n");
		return 0;
	}
	else if(c==0){
		printf("0\n");
		return 0;
	}
	dfs(r,-1);
	int ln=ans.size();
	if(req[r]!=cur[r]) ln--;
	printf("%d\n",ln);
	for(int i=0;i<ln;i++){
		printf("%d%c",ans[i]+1,i==ln-1?'\n':' ');
	}
	return 0;
}
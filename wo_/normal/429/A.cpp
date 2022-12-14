#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> G[100100];

int init[100100],goal[100100];

bool st0[100100],st1[100100];

int par[100100];

int cnt=0;
bool picked[100100];

void dfs(int v,int p){
	int a=init[v];
	if(st1[v]==true) a^=1;
//	printf("%d %d %d %d\n",v,init[v],goal[v],a);
	if(a!=goal[v]){
		st1[v]=(!st1[v]);
		picked[v]=true;
		cnt++;
//		printf("pk %d\n",v+1);
	}
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]==p) continue;
		if(st1[v]) st0[G[v][i]]=true;
		if(st0[v]) st1[G[v][i]]=true;
	}
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]==p) continue;
		dfs(G[v][i],v);
	}
	par[v]=p;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		st0[i]=false;
		st1[i]=false;
	}
	for(int i=0;i<N;i++) scanf("%d",init+i);
	for(int i=0;i<N;i++) scanf("%d",goal+i);
	dfs(0,-1);
	printf("%d\n",cnt);
	for(int i=0;i<N;i++) if(picked[i]) printf("%d\n",i+1);
	return 0;
}
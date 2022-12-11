#include <cstdio>
#include <vector>
#include <cstring>
#define il __inline__ __attribute__((always_inline))
using namespace std;
#define max_n 500000
vector<int>g[max_n+1],vec[max_n+1];
int dep[max_n+1],par[max_n+1];
void dfs(const int& u){
	for(int v:g[u])
		if(!dep[v]){
			vec[dep[v]=dep[u]+1].push_back(v),par[v]=u;
			dfs(v);
		}
}
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		g[i].clear(),vec[i].clear();
	for(int u,v; m; g[u].push_back(v),g[v].push_back(u),--m)
		scanf("%d%d",&u,&v);
	memset(dep+1,0,n<<2);
	dep[1]=1,vec[1].push_back(1);
	dfs(1);
	int mx=1,u=1;
	for(int i=2; i<=n; ++i)
		if(dep[i]>mx)
			mx=dep[i],u=i;
	if(mx*2>=n){
		puts("PATH");
		printf("%d\n",mx);
		for(; u!=1; u=par[u])
			printf("%d ",u);
		puts("1");
	}
	else{
		puts("PAIRING");
		int cnt=0;
		for(int i=1; i<=mx; ++i)
			cnt+=vec[i].size()/2;
		printf("%d\n",cnt);
		for(int i=1; i<=mx; ++i)
			for(int j=vec[i].size(); (j-=2)>=0; )
				printf("%d %d\n",vec[i][j],vec[i][j+1]);
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}
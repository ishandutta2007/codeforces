#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_n=100000;
vector<int>g[max_n+1];
int deg[max_n+1];
void dfs(const int u,const int p=0,const int d=1){
	deg[u]*=d;
	for(auto v:g[u])
		if(v!=p)
			dfs(v,u,-d);
}
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		g[i].clear(),deg[i]=0;
	for(int i=n,u,v; --i; g[u].push_back(v),g[v].push_back(u),++deg[u],++deg[v])
		scanf("%d%d",&u,&v);
	int rt=1,d=deg[1];
	for(int i=2; i<=n; ++i)
		if(deg[i]>d)
			rt=i,d=deg[i];
	dfs(rt);
	for(int i=1; i<=n; ++i)
		printf("%d ",deg[i]);
	puts("");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
#define max_q 300000
int par[max_n+1],p[max_n+1];
int find(int&x){
	return p[x]?x=find(p[x]):x;
}
vector<int>g[max_n+1];
pair<int,int>que[max_q+1];
bool vis[max_n+1];
bool dfs(ci u,ci t,ci p=0,ci d=1){
	if(vis[u])
		return 0;
	vis[u]=1;
	if(u==t){
		printf("%d\n",d);
		printf("%d",u);
		return 1;
	}
	for(int v:g[u])
		if(dfs(v,t,u,d+1)){
			printf(" %d",u);
			return 1;
		}
	return 0;
}
il void test(){
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i){
		int u,v,a,b;
		scanf("%d%d",&u,&v);
		a=u,b=v;
		find(u);
		find(v);
		if(u!=v)
			g[a].push_back(b),g[b].push_back(a),p[u]=v;
	}
	scanf("%d",&q);
	for(int i=1,u,v; i<=q; ++i){
		scanf("%d%d",&u,&v);
		vis[u]^=1,vis[v]^=1;
		que[i].first=u,que[i].second=v;
	}
	int t=0;
	for(int i=1; i<=n; ++i)
		if(vis[i])
			++t;
	if(t)
		printf("NO\n%d\n",t>>1);
	else{
		puts("YES");
		for(int i=1; i<=q; ++i){
			memset(vis,0,sizeof(vis));
			dfs(que[i].second,que[i].first);
			putchar('\n');
		}
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}
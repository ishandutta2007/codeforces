#include <cstdio>
#include <vector>
using namespace std;
constexpr int max_n=200000;
vector<int> g[max_n+1];
int dfs(const int&u,const int&p=0){
	int sum=0,cnt=0;
	for(const int&v:g[u])
		if(v!=p){
			const int x=dfs(v,u);
			if(x)
				sum+=x;
			else
				++cnt;
		}
	return cnt?sum+cnt-1:sum;
}
void test(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return;
	}
	for(int i=1; i<=n; ++i)
		g[i].clear();
	for(int i=n,u,v; --i; g[u].emplace_back(v),g[v].emplace_back(u))
		scanf("%d%d",&u,&v);
	int rt=0,mxdeg=0;
	for(int i=1; i<=n; ++i)
		if(g[i].size()>mxdeg)
			mxdeg=g[i].size(),rt=i;
	if(mxdeg<=2){
		puts("1");
		return;
	}
	printf("%d\n",dfs(rt));
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}
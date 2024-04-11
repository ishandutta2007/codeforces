#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> adj[10001];
int color[10001];

int dfs(int cur,int c){
	int res=0;
	if(c!=color[cur]) {
		res++;
		c=color[cur];
	}
	for(auto &it:adj[cur]) {
		res+=dfs(it,c);
	}
	return res;
}
int main() {
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		int v;
		scanf("%d",&v);
		adj[v].push_back(i);
	}
	for(int i=1;i<=n;i++) scanf("%d",color+i);
	printf("%d\n",dfs(1,0));
	return 0;
}
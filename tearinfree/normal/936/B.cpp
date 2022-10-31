#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n,m,cache[100001][2],vc[100001][2];
vector<int> adj[100001];

bool DP(int cur,int i) {
	int &ret=cache[cur][i];
	if(ret!=-1) return ret;

	int nx=i^1;
	vc[cur][i]=1;
	ret=0;
	if(adj[cur].size() == 0) {
		return i==1;
	}
	for(auto &it:adj[cur]) if(!vc[it][nx]) {
		if(DP(it,nx)) {
			cache[cur][i] = it;
			return true;
		}
	}
	return false;
}
void trace(int cur,int i) {
	printf("%d ",cur);
	if(cache[cur][i] == 0) return;
	trace(cache[cur][i], i^1);
}

int vis[100001],g,gn[100001],gs[100001],as[100001];
vector<int> radj[100001];
stack<int> stk;

void dfs1(int cur) {
	vis[cur]=1;
	for(auto &it:adj[cur]) if(!vis[it]) dfs1(it);
	stk.push(cur);
}
void dfs2(int cur) {
	vis[cur]=1;
	for(auto &it:radj[cur]) if(!vis[it]) dfs2(it);
	gs[g]++; gn[cur]=g;
}
bool check(int cur) {
	vis[cur]=1;
	if(gs[gn[cur]]>1) return true;
	for(auto &it:adj[cur]) if(!vis[it]) {
		if(check(it)) return true;
	}
	return false;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int v;
		scanf("%d",&v);
		adj[i].resize(v);
		while(v--) {
			scanf("%d",&adj[i][v]);
		}
	}
	
	int s;
	scanf("%d",&s);
	memset(cache,-1,sizeof(cache));
	if(DP(s,0)) {
		puts("Win");
		trace(s,0);
	}
	else {
		for(int cur=1;cur<=n;cur++) for(auto &it:adj[cur]) as[it]++;
		for(int i=1;i<=n;i++) radj[i].resize(as[i]);
		fill(as,as+n+1,0);
		for(int cur=1;cur<=n;cur++) for(auto &it:adj[cur]) {
			radj[it][as[it]++]=cur;
		}
		fill(vis,vis+n+1,0);
		for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i);
		fill(vis,vis+n+1,0);
		while(!stk.empty()) {
			int cur=stk.top(); stk.pop();
			if(!vis[cur]) {
				dfs2(cur);
				g++;
			}
		}
		fill(vis,vis+n+1,0);
		puts(check(s) ? "Draw" : "Lose");
	}
	
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
#include <queue>

using namespace std;

int n,m,h,arr[100001];
vector<int> adj[100001],radj[100001];

int vis[100001],gn[100001],g;
int gs=1000000,gm=0;

stack<int> stk;
void dfs1(int cur) {
	vis[cur]=1;
	for(auto &it:adj[cur]) if(!vis[it]) dfs1(it);
	stk.push(cur);
}
void dfs2(int cur) {
	vis[cur]=1;
	gn[cur] =g;
	for(auto &it:radj[cur]) if(!vis[it]) dfs2(it);
}
void dfs3(int cur) {
	queue<int> que;
	que.push(cur);
	vis[cur]=1;
	
	int s=1,mm=gn[cur],f=0;
	while(!que.empty()) {
		int cur=que.front();que.pop();
		for(auto &it:adj[cur]) {
			if(gn[it] != mm) f=1;

			if(!vis[it]) {
				if(gn[it] != mm) dfs3(it);
				else {
					que.push(it);
					vis[it]=1;
					s++;
				}
			}
		}
	}

	if(!f) {
		if(gs > s) {
			gs=s;
			gm=mm;
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if( (arr[b]-arr[a]+h)%h == 1) {
			adj[a].push_back(b);
			radj[b].push_back(a);
		}
		if( (arr[a]-arr[b]+h)%h == 1) {
			adj[b].push_back(a);
			radj[a].push_back(b);
		}
	}
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
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			dfs3(i);
		}
	}
	
	vector<int> ans;
	for(int i=1;i<=n;i++) if(gn[i] == gm) {
		ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(auto &it:ans) printf("%d ",it);
	
	return 0;
}
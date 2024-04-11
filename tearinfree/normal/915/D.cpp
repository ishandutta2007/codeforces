#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
typedef long long lli;

struct graph{
	int n,vis[501],flag;
	vector<int> adj[501],radj[501],r;
	stack<int> stk;
	graph():n(0) {}
	void init(int nn,int f) {
		while(!stk.empty()) stk.pop();
		for(int i=1;i<=n;i++) adj[i].clear(),radj[i].clear();
		n=nn;
		for(int i=1;i<=n;i++) vis[i]=0;
		flag=f;
	}
	void addEdge(int u,int v) {
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	void dfs(int cur) {
		vis[cur]=1;
		for(auto &it:adj[cur]) if(!vis[it]) dfs(it);
		stk.push(cur);
	}
	int find(int cur,vector<int> &tmp) {
		int s=1;
		vis[cur]=1;
		tmp.push_back(cur);
		for(auto &it:radj[cur]) if(!vis[it]) s+=find(it,tmp);
		return s;
	}
	int SCC() {
		for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
		fill(vis,vis+n+1,0);

		int t=0;
		while(!stk.empty()) {
			int cur=stk.top();stk.pop();
			vector<int> tmp;
			if(!vis[cur]) {
				int s=find(cur,tmp);
				if(s>=2) {
					if(t>=1 || !flag) return 2;
					r=tmp;
					t++;
				}
			}
		}
		return t;
	}
}g,ng,tg;
	
int n,m,co[501],ind[501],outd[501];
vector<int> adj[501];

int main() {
	scanf("%d%d",&n,&m);
	g.init(n,1);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		g.addEdge(a,b);
	}
	int s=g.SCC();
	if(s==0) return !printf("YES\n");
	else if(s==2) return !printf("NO");

	vector<int> res=g.r;
	for(auto &it:res) co[it]=1;
	for(auto &cur:res) {
		if(!co[cur]) continue;
		for(auto &it:g.adj[cur]) if(co[it]) {
			ind[cur]++; outd[it]++;
			adj[cur].push_back(it);
		}
	}

	for(auto &it:res) {
		if(ind[it]>=2 && outd[it]>=2) continue;
		ng.init(n,0);
		for(auto &cur:res) {
			if(cur==it) continue;
			for(auto &jt:adj[cur]) if(it!=jt) ng.addEdge(cur,jt);
		}
		if(ng.SCC()==0) return !printf("YES");
	}
	puts("NO");

	return 0;
}
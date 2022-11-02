#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0'; ch=getchar();} while ('0'<=ch&&ch<='9');t*=f;
}
const int maxn=(2e5)+10;
int n,dis[maxn],fa[maxn],vis[maxn],ans;
vector<int> g[maxn];
priority_queue<pair<int,int> > q;
void dfs(int u,int p) {
	fa[u]=p;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (v==p) continue;
		dis[v]=dis[u]+1;
		if (dis[v]>2) q.push(make_pair(dis[v],v));
		else vis[v]=1;
		dfs(v,u);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<n;i++) {
		int x,y; read(x); read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	while (!q.empty()) {
		int u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		u=fa[u];
		vis[u]=1;
		ans++;
		for (int i=0;i<g[u].size();i++) vis[g[u][i]]=1;
	}
	printf("%d\n",ans);
	return 0;
}
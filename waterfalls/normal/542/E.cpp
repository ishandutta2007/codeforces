#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1013];
int visited[1013];
int dist[1013];

vector<int> has;
void dfs(int x, int c=1) {
	has.push_back(x);
	visited[x] = c;
	for (int i: adj[x]) if (!visited[i]) dfs(i,3-c);
}

queue<int> frontier;
int bfs(int s) {
	for (int i=1;i<=n;i++) dist[i] = 0;
	dist[s] = 1;
	frontier.push(s);
	while (frontier.size()>0) {
		int x = frontier.front();
		frontier.pop();
		for (int i: adj[x]) if (!dist[i]) {
			dist[i] = dist[x]+1;
			frontier.push(i);
		}
	}
	return *max_element(dist,dist+n+1)-1;
}

int solve(int x) {
	has.clear();
	dfs(x);
	int res = 0;
	for (int i: has) res = max(res,bfs(i));
	return res;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=1;i<=n;i++) if (!visited[i]) dfs(i);
	int ok = 1;
	for (int i=1;i<=n;i++) for (int j: adj[i]) if (visited[i]==visited[j]) ok = 0;
	if (!ok) return printf("-1\n"), 0;
	for (int i=1;i<=n;i++) visited[i] = 0;
	int ans = 0;
	for (int i=1;i<=n;i++) if (!visited[i]) ans+=solve(i);
	printf("%d\n",ans);

	return 0;
}
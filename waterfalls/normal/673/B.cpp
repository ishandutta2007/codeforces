#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100013];
int vis[100013];
vector<int> has[2], res[2];
bool lone[100013];

void dfs(int x, int c=2) {
	vis[x] = c;
	has[c&1].push_back(x);
	for (int i: adj[x]) {
		if (!vis[i]) dfs(i,c^1);
		else if (vis[i]!=(c^1)) {
			printf("0\n");
			exit(0);
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=1;i<=n;i++) if (!vis[i]) {
		dfs(i);
		if (!has[1].size()) lone[i] = 1;
		else {
			if (has[0][0]>has[1][0]) swap(has[0],has[1]);
			res[0].insert(res[0].end(),has[0].begin(),has[0].end());
			res[1].insert(res[1].end(),has[1].begin(),has[1].end());
		}
		has[0].clear();
		has[1].clear();
	}
	res[0].push_back(0);
	res[1].push_back(n+1);
	sort(res[0].begin(),res[0].end());
	sort(res[1].begin(),res[1].end());
	if (res[0].back()>res[1].front()) return printf("0\n"), 0;
	int ans = 1;
	for (int i=res[0].back();i<=res[1].front();i++) {
		ans+=lone[i];
	}
	ans-=(res[0].back()==0);
	ans-=(res[1].front()==n+1);
	printf("%d\n",ans);

	return 0;
}
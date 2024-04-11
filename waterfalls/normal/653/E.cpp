#include <bits/stdc++.h>
using namespace std;

int n,m,k;
set<int> adj[300013];
int conn = 0;

set<int> unvisited;
void dfs(int x) {
	int i = 0;
	while (true) {
		auto it = unvisited.upper_bound(i);
		if (it==unvisited.end()) break;
		i = *it;
		if (adj[x].count(i)) continue;
		if (x==1) conn+=1;
		unvisited.erase(it);
		dfs(i);
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	int deg = n-1;
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].insert(b);
		adj[b].insert(a);
		if (min(a,b)==1) deg-=1;
	}
	for (int i=2;i<=n;i++) unvisited.insert(i);
	dfs(1);
	if (unvisited.size()>0) printf("impossible\n");
	else if (conn<=k && k<=deg) printf("possible\n");
	else printf("impossible\n");

	return 0;
}
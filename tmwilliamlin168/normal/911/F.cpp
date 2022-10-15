#include <bits/stdc++.h>
using namespace std;

vector<int> *graph;
int *dep, *dep2;
vector<pair<int, int>> ops;
long long t=0;
int root, bot;

inline void op(int a, int b, int d) {
	ops.push_back(make_pair(a+1, b+1));
	t+=d;
}

void dfs1(int u, int p) {
	if(p!=-1)
		dep2[u]=dep2[p]+1;
	for(int i=0; i<graph[u].size()-(p!=-1); ++i) {
		if(graph[u][i]==p)
			swap(graph[u][i], graph[u].back());
		int v=graph[u][i];
		dfs1(v, u);
		dep[u]=max(dep[v]+1, dep[u]);
		if(dep[v]>dep[graph[u][0]])
			swap(graph[u][i], graph[u][0]);
	}
}

void dfs2(int u, int p, int d, int d2) {
	//cout << u << " " << p << " " << d << endl;
	if(graph[u].size()-(p!=-1)) {
		dfs2(graph[u][0], u, d?d+1:0, d2);
		for(int i=1; i<graph[u].size()-(p!=-1); ++i)
			dfs2(graph[u][i], u, d?d+1:max(dep[u], dep2[u])+1, !d&&dep[u]>dep2[u]?bot:d2);
	}
	if(d)
		op(d2, u, d);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	graph = new vector<int>[n];
	dep = new int[n](), dep2 = new int[n]();
	for(int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs1(0, -1);
	for(; !root||graph[root].size()>1; root=graph[root][0]);
	memset(dep, 0, 4*n), memset(dep2, 0, 4*n);
	dfs1(root, -1);
	for(bot=root; bot==root||graph[bot].size()>1; bot=graph[bot][0]);
	dfs2(root, -1, 0, root);
	for(; root!=bot; root=graph[root][0])
		op(bot, root, dep[root]);
	cout << t << "\n";
	for(pair<int, int> p : ops)
		cout << p.first << " " << p.second << " " << p.second << "\n";
}
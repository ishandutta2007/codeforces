#include <bits/stdc++.h>
using namespace std;

vector<int> *graph;
bool *c;

void dfs(int u, int p) {
	if(p!=-1)
		c[u]=!c[p];
	for(int v : graph[u])
		if(v!=p)
			dfs(v, u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	graph = new vector<int>[n];
	c = new bool[n]();
	for(int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, -1);
	int a=0;
	for(int i=0; i<n; ++i)
		a+=c[i];
	cout << (long long)a*(n-a)-(n-1);
}
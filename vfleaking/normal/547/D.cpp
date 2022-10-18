#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
using namespace std;

const int NX = 200000;
const int NY = 200000;
const int NV = NX + NY;
const int MaxN = 200000;

set<pair<int, int> > li;
set<int> adj[NV];

void dfs(int v) {
	if (!adj[v].empty()) {
		int u = *adj[v].begin();
		li.insert(make_pair(v, u));
		adj[v].erase(u), adj[u].erase(v);
		dfs(u);
	}
}

int main() {
	int n;
	static int px[MaxN], py[MaxN];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &px[i], &py[i]);
		px[i]--, py[i]--;
		adj[px[i]].insert(NX + py[i]);
		adj[NX + py[i]].insert(px[i]);
	}
	
	for (int v = 0; v < NV; v++) {
		if (adj[v].size() % 2 == 1) {
			dfs(v);
		}
	}
	for (int v = 0; v < NV; v++) {
		while (adj[v].size() > 0) {
			dfs(v);
		}
	}
	
	for (int i = 0; i < n; i++) {
		putchar(li.count(make_pair(px[i], NX + py[i])) ? 'r' : 'b');
	}
	printf("\n");
	
	return 0;
}
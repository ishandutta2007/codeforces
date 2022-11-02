#include <cstdio>
#include <set>
using namespace std;
#define red 0
#define blue 1
#define nada 10

struct Edge {
	int from, to;
	int color;
	inline int other(int v) const { return v == from? to : from; }
} es[200005];

set<int> adj[400005];

void dfs(int u, int color) {
	if(adj[u].size()) {
		int f = *adj[u].begin();
		int v = es[f].other(u);
		adj[u].erase(adj[u].begin());
		adj[v].erase(adj[v].find(f));
		es[f].color = color;
		dfs(v, !color);
	}
}

int map_x[200005], map_y[200005];
int p_n;

int main() {
	int n, i, x, y;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if(!map_x[x]) map_x[x] = ++p_n;
		if(!map_y[y]) map_y[y] = ++p_n;
		x = map_x[x]; y = map_y[y];
		Edge &e = es[i];
		e.from = x; e.to = y; e.color = nada;
		adj[x].insert(i);
		adj[y].insert(i);
	}
	for(i = 1; i <= p_n; i++) {
		int color = blue;
		while(adj[i].size()) 
			dfs(i, color = !color);
	}
	char str[200005];
	for(i = 0; i < n; i++)
		str[i] = (es[i].color == red? 'r' : 'b');
	str[n] = '\0';
	puts(str);
	return 0;
}
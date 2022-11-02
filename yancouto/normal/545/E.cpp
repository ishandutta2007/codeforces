#include <cstdio>
#include <queue>
#include <list>
using namespace std;

struct ad {
	int v, w;
	int id;
};

int n, m;
list<ad> adj[300002];

typedef unsigned long long ull;

struct Node {
	int v;
	ull total;
	int edge;
	int edge_n;
	bool operator < (const Node &o) const { return (total == o.total)? edge > o.edge : total > o.total; }
};

int seen[300003];
ull prim(int s) {
	ull sum = 0;
	priority_queue<Node> pq;
	pq.push({s, 0, 0, -1});
	while(!pq.empty()) {
		Node no = pq.top();
		pq.pop();
		if(seen[no.v]) continue;
		// printf("looking at {%d, %llu, %d, %d}\n", no.v, no.total, no.edge, no.edge_n);
		sum += no.edge;
		seen[no.v] = no.edge_n;
		for(list<ad>::iterator it = adj[no.v].begin(); it != adj[no.v].end(); ++it)
			if(!seen[it->v])
				pq.push({it->v, no.total + it->w, it->w, it->id});
	}
	return sum;
}

int main() {
	int u, v, w;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w); u--; v--;
		adj[u].push_back({v, w, i + 1});
		adj[v].push_back({u, w, i + 1});
	}
	scanf("%d", &u); u--;
	printf("%I64d\n", prim(u));
	for(int i = 0; i < n; i++)
		if(i != u)
			printf("%d ", seen[i]);
	putchar('\n');
	return 0;
}
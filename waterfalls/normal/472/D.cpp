#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

struct Edge {
	int a,b,w;
	bool operator<(Edge o) const { return w<o.w; }
};

int p[2013], s[2013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a==b) return;
	p[a] = b;
	s[b]+=(s[a]==s[b]);
}

int n;
int d[2013][2013];
vector<Edge> edges;
vector<pair<int,int> > adj[2013];

void dfs(int x, int s, int p=0, long long above=0) {
	if (d[s][x]!=above) printf("NO\n"), exit(0);
	for (auto i: adj[x]) if (i.A!=p) dfs(i.A,s,x,above+i.B);
}

int main() {
	scanf("%d",&n);
	iota(p,p+n+1,0);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		scanf("%d",&d[i][j]);
		edges.push_back({i,j,d[i][j]});
	}
	sort(edges.begin(),edges.end());
	for (auto e: edges) {
		if (find(e.a)==find(e.b)) continue;
		if (e.w==0) printf("NO\n"), exit(0);
		merge(e.a,e.b);
		adj[e.a].push_back(MP(e.b,e.w));
		adj[e.b].push_back(MP(e.a,e.w));
	}
	for (int i=1;i<=n;i++) dfs(i,i);
	printf("YES\n");

	return 0;
}
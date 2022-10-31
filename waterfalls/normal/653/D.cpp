#include <bits/stdc++.h>
using namespace std;

int n;

const int INF = 1e9;

vector<int> adj[53];
int res[53][53];
const int source = 1;
int sink;

int h[53];
queue<int> frontier;
int on[53];

bool level() {
	for (int i=1;i<=n;i++) h[i] = INF;
	h[source] = 0;
	frontier.push(source);
	while (frontier.size()>0) {
		int x = frontier.front();
		frontier.pop();
		for (int i: adj[x]) if (res[x][i] && h[i]==INF) {
			h[i] = h[x]+1;
			frontier.push(i);
		}
	}
	return (h[sink]!=INF);
}
int dfs(int x, int c) {
	if (x==sink) return c;
	int flow = 0;
	while (on[x]<adj[x].size()) {
		int i = adj[x][on[x]];
		if (h[i]==h[x]+1 && res[x][i]) {
			int go = dfs(i,min(c-flow,res[x][i]));
			res[x][i]-=go;
			res[i][x]+=go;
			flow+=go;
			if (flow==c) break;
		}
		on[x]+=1;
	}
	return flow;
}
int maxflow() {
	int flow = 0;
	while (true) {
		if (!level()) break;
		for (int i=1;i<=n;i++) on[i] = 0;
		flow+=dfs(source,INF);
	}
	return flow;
}

#define MP make_pair
#define A first
#define B second

int m,x;
vector<pair<pair<int,int>,int> > edges;

bool check(double k) {
	double each = k/x;
	for (int i=1;i<=n;i++) adj[i].clear();
	memset(res,0,sizeof res);
	for (auto p: edges) {
		if (!res[p.A.B][p.A.A]) {
			adj[p.A.A].push_back(p.A.B);
			adj[p.A.B].push_back(p.A.A);
		}
		res[p.A.A][p.A.B] = min(p.B/each,x+1.);
	}
	return (maxflow()>=x);
}

int main() {
	scanf("%d%d%d",&n,&m,&x);
	sink = n;
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edges.push_back(MP(MP(a,b),c));
	}
	double low = 0;
	double high = 6e8;
	for (int r=0;r<88;r++) {
		if (check((low+high)/2)) low = (low+high)/2;
		else high = (low+high)/2;
	}
	printf("%1.9f\n",low);

	return 0;
}
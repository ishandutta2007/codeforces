#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
struct Edge { int u,v,c,t,i; };

int n,m;
vector<Edge> edges;

vector<int> adj[300013];
vector<int> jda[300013];
int visited[300013];
stack<int> topo;
vector<vector<int> > sccs;
int where[300013];
int val[150013];

vector<int> reset[300013];
map<int,map<int,vector<int> > > has;
vector<int> neigh[50013];
void conn(int a, int b) {
	reset[a^1].push_back(b);
	reset[b^1].push_back(a);
}
void make() {
	for (Edge e: edges) {
		has[e.c][e.u].push_back(e.i);
		has[e.c][e.v].push_back(e.i);
		neigh[e.u].push_back(e.i);
		neigh[e.v].push_back(e.i);
	}
	for (auto it: has) for (auto i: it.B) {
		if (i.B.size()>2) printf("No\n"), exit(0);
		if (i.B.size()<2) continue;
		conn(i.B[0]*2,i.B[1]*2);
		conn(i.B[0]*2+1,i.B[1]*2+1);
	}
	int on = m;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<neigh[i].size();j++) {
			conn((on+j)*2,neigh[i][j]*2+1);
			if (j) conn((on+j-1)*2+1,(on+j)*2);
			if (j) conn(neigh[i][j]*2+1,(on+j-1)*2+1);
		}
		on+=neigh[i].size();
	}
}

void dfs(int x, int v, bool w) {
	visited[x] = v;
	if (w==1) {
		sccs.back().push_back(x);
		where[x] = sccs.size();
	}
	if (w==0) for (int i: adj[x]) if (visited[i]<v) dfs(i,v,w);
	if (w==1) for (int i: jda[x]) if (visited[i]<v) dfs(i,v,w);
	if (w==0) topo.push(x);
}

bool check(int K) {
	for (int i=0;i<6*m;i++) adj[i].clear(), jda[i].clear(), visited[i] = 0, val[i] = 0;
	sccs.clear();
	for (int i=0;i<6*m;i++) for (int j: reset[i]) {
		adj[i].push_back(j);
		jda[j].push_back(i);
	}
	for (Edge e: edges) if (e.t>K) {
		adj[e.i*2].push_back(e.i*2+1);
		jda[e.i*2+1].push_back(e.i*2);
	}
	for (int i=0;i<6*m;i++) if (!visited[i]) dfs(i,1,0);
	while (topo.size()>0) {
		sccs.push_back(vector<int>());
		dfs(topo.top(),2,1);
		while (topo.size()>0 && visited[topo.top()]==2) topo.pop();
	}
	reverse(sccs.begin(),sccs.end());
	for (auto v: sccs) for (int i: v) {
		if (val[i/2]) continue;
		val[i/2] = i%2+1;
	}
	for (int i=0;i<3*m;i++) if (where[i*2]==where[i*2+1]) return false;
	return true;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		Edge e;
		scanf("%d%d%d%d",&e.u,&e.v,&e.c,&e.t);
		e.i = i;
		edges.push_back(e);
	}
	make();
	if (!check(1e9+2)) return printf("No\n"), 0;
	int low = -1;
	int high = 1e9+2;
	while (high-low>1) {
		if (check((low+high+1)/2)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	check(high);
	vector<int> res;
	for (int i=0;i<m;i++) if (val[i]==1) res.push_back(i);
	printf("Yes\n");
	printf("%d %d\n",high,res.size());
	for (int i: res) printf("%d ",i+1);
	printf("\n");

	return 0;
}
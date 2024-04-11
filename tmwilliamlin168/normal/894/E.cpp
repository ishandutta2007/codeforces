#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Edge {
	int x, y;
	ll w;
	Edge(int x, int y, ll w) {
		this->x=x;
		this->y=y;
		this->w=w;
	}
};

vector<Edge> *graph, *graphRev, *sccsGraph;
bool *visited;
int *sccs, sccI;
stack<int> st;
ll *sccsW1, *sccsW2;

void dfs1(int node) {
	visited[node]=true;
	for(Edge e : graph[node])
		if(!visited[e.y])
			dfs1(e.y);
	st.push(node);
}

void dfs2(int node, int sccI) {
	visited[node]=false;
	sccs[node]=sccI;
	for(Edge e : graphRev[node])
		if(visited[e.y])
			dfs2(e.y, sccI);
}

void dfs3(int node) {
	visited[node]=true;
	for(Edge e : sccsGraph[node]) {
		if(!visited[e.y])
			dfs3(e.y);
		sccsW2[node]=max(sccsW2[node], e.w+sccsW2[e.y]);
	}
	sccsW2[node]+=sccsW1[node];
}

ll getEdgeTotalW(ll w) {
	ll l=0, r=15000, ans=l;
	while(l<=r) {
		ll mid=(l+r)/2;
		if(mid*(mid+1)/2<=w) {
			ans=mid;
			l=mid+1;
		} else
			r=mid-1;
	}
	return w*(ans+1)-(ans+2)*(ans+1)*ans/6;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	graph = new vector<Edge>[n], graphRev = new vector<Edge>[n];
	visited = new bool[n]();
	sccs = new int[n];
	for(int i=0; i<m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;
		graph[x].push_back(Edge(x, y, w));
		graphRev[y].push_back(Edge(y, x, w));
	}
	int s;
	cin >> s;
	--s;
	for(int i=0; i<n; ++i)
		if(!visited[i])
			dfs1(i);
	while(!st.empty()) {
		int node=st.top();
		st.pop();
		if(visited[node]) {
			dfs2(node, sccI);
			++sccI;
		}
	}
	sccsGraph = new vector<Edge>[sccI];
	sccsW1 = new ll[sccI](), sccsW2 = new ll[sccI]();
	for(int i=0; i<n; ++i) {
		for(Edge e : graph[i]) {
			if(sccs[i]!=sccs[e.y])
				sccsGraph[sccs[i]].push_back(Edge(sccs[i], sccs[e.y], e.w));
			else
				sccsW1[sccs[i]]+=getEdgeTotalW(e.w);
		}
	}
	dfs3(sccs[s]);
	cout << sccsW2[sccs[s]];
}
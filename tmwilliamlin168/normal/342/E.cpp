#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

vector<int> *graph;
int *f, **depT;
int *centP, *sz;

inline int lg2(int x) {
	return 31-__builtin_clz(x);
}

void dfs1(int u, int p, int dep, int &depTi) {
	f[u]=depTi;
	depT[0][depTi++]=dep;
	for(int v : graph[u]) {
		if(v==p)
			continue;
		dfs1(v, u, dep+1, depTi);
		depT[0][depTi++]=dep;
	}
}

inline int dist(int u, int v) {
	if(u==v)
		return 0;
	if(f[u]>f[v])
		swap(u, v);
	int k=lg2(f[v]-f[u]);
	return depT[0][f[u]]+depT[0][f[v]]-2*min(depT[k][f[u]], depT[k][f[v]-(1<<k)+1]);
}

void dfs2(int u, int p) {
	sz[u]=1;
	for(int v : graph[u]) {
		if(v==p||centP[v]!=-1)
			continue;
		dfs2(v, u);
		sz[u]+=sz[v];
	}
}

int dfs3(int u, int p, int n) {
	for(int v : graph[u])
		if(v!=p&&centP[v]==-1&&sz[v]>n/2)
			return dfs3(v, u, n);
	return u;
}

void cd(int u, int p) {
	int c=dfs3(u, -1, sz[u]);
	dfs2(c, -1);
	centP[c]=p;
	for(int v : graph[c])
		if(centP[v]==-1)
			cd(v, c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	graph = new vector<int>[n];
	for(int i=0; i<n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	f = new int[n], depT = new int*[lg2(2*n-1)+1];
	depT[0] = new int[2*n-1];
	int depTi=0;
	dfs1(0, -1, 0, depTi);
	for(int i=1; i<=lg2(2*n-1); ++i) {
		depT[i] = new int[2*n-(1<<i)];
		for(int j=0; j<2*n-(1<<i); ++j)
			depT[i][j]=min(depT[i-1][j], depT[i-1][j+(1<<(i-1))]);
	}
	centP = new int[n];
	memset(centP, -1, 4*n);
	sz = new int[n];
	dfs2(0, -1);
	cd(0, -2);
	int *minD = new int[n];
	for(int i=0; i<n; ++i)
		minD[i]=INF;
	int t, v1, v2=0;
	while(v2!=-2) {
		minD[v2]=min(dist(0, v2), minD[v2]);
		v2=centP[v2];
	}
	while(m--) {
		cin >> t >> v1;
		v2=--v1;
		if(t==1) {
			while(v2!=-2) {
				minD[v2]=min(dist(v1, v2), minD[v2]);
				v2=centP[v2];
			}
		} else {
			int _min=INT_MAX;
			while(v2!=-2) {
				_min=min(minD[v2]+dist(v1, v2), _min);
				v2=centP[v2];
			}
			cout << _min << "\n";
		}
	}
}
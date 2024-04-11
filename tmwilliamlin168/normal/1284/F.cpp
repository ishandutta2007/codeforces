#include <bits/stdc++.h>
using namespace std;

const int mxN=2.5e5;
int n, dt, ds[mxN], de[mxN], anc[mxN][18], p[mxN];
vector<int> adj1[mxN], adj2[mxN];
vector<array<int, 4>> ans;

int find(int x) {
	return x^p[x]?p[x]=find(p[x]):x;
}

void dfs1(int u=0, int p=-1) {
	ds[u]=dt++;
	anc[u][0]=p;
	for(int i=1; i<18; ++i)
		anc[u][i]=~anc[u][i-1]?anc[anc[u][i-1]][i-1]:-1;
	for(int v : adj1[u])
		if(v^p)
			dfs1(v, u);
	de[u]=dt;
}

void dfs2(int u=0, int pu=-1) {
	for(int v : adj2[u]) {
		if(v==pu)
			continue;
		dfs2(v, u);
		if(ds[find(v)]<ds[u]&&ds[u]<de[find(v)]) {
			int w=u;
			for(int i=17; ~i; --i)
				if(~anc[w][i]&&ds[find(v)]<ds[anc[w][i]]&&find(anc[w][i])^find(v))
					w=anc[w][i];
			p[w]=v;
			ans.push_back({w, anc[w][0], v, u});
		} else {
			int w=find(v);
			p[w]=anc[w][0];
			ans.push_back({w, anc[w][0], v, u});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	dfs1();
	iota(p, p+n, 0);
	dfs2();
	cout << n-1 << "\n";
	for(array<int, 4> a : ans)
		cout << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " " << a[3]+1 << "\n";
}
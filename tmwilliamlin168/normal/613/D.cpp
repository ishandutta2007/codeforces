#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, dt, fo[mxN], q, a[mxN], st[mxN];
vector<int> adj[mxN], adj2[mxN];
array<int, 2> td[18][2*mxN-1];
bool b[mxN];

void dfs(int u=0, int p=-1, int d=0) {
	td[0][dt]={d, u};
	fo[u]=dt++;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		dfs(v, u, d+1);
		td[0][dt++]={d, u};
	}
}

int lca(int u, int v) {
	u=fo[u];
	v=fo[v];
	if(u>v)
		swap(u, v);
	int k=31-__builtin_clz(v-u+1);
	return min(td[k][u], td[k][v-(1<<k)+1])[1];
}

array<int, 2> dfs2(int u=0, int p=-1) {
	int c=0, d=0;
	for(int v : adj2[u]) {
		if(v==p)
			continue;
		array<int, 2> a=dfs2(v, u);
		c+=a[0];
		d+=a[1];
		if(b[u]&&b[v]&&td[0][fo[v]-1][1]==u)
			c=n;
	}
	adj2[u].clear();
	return {c+(b[u]?d:d>=2), b[u]||d==1};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for(int i=1; i<18; ++i)
		for(int j=0; j+(1<<i)<2*n; ++j)
			td[i][j]=min(td[i-1][j], td[i-1][j+(1<<i-1)]);
	cin >> q;
	for(int k; q--; ) {
		cin >> k;
		for(int i=0; i<k; ++i) {
			cin >> a[i], --a[i];
			b[a[i]]=1;
		}
		sort(a, a+k, [](const int &i, const int &j) {
			return fo[i]<fo[j];
		});
		int sth=0;
		st[sth++]=0;
		for(int i=!a[0]; i<k; ++i) {
			int u=lca(a[i], st[sth-1]);
			if(u^st[sth-1]) {
				for(; fo[u]<fo[st[sth-2]]; --sth)
					adj2[st[sth-2]].push_back(st[sth-1]);
				adj2[u].push_back(st[--sth]);
				if(u^st[sth-1])
					st[sth++]=u;
			}
			st[sth++]=a[i];
		}
		for(; sth>1; --sth)
			adj2[st[sth-2]].push_back(st[sth-1]);
		int ans=dfs2()[0];
		cout << (ans>=n?-1:ans) << "\n";
		for(int i=0; i<k; ++i)
			b[a[i]]=0;
	}
}
#include <bits/stdc++.h>
using namespace std;

#define ar array

int n, m;
vector<string> c, s;
map<char, ar<int, 2>> d;
vector<vector<bool>> vis1, vis2;
vector<ar<int, 2>> cyc;
vector<int> a;
vector<vector<vector<ar<int, 2>>>> adj;

ar<int, 2> nxt(ar<int, 2> u) {
	return {u[0]+d[s[u[0]][u[1]]][0], u[1]+d[s[u[0]][u[1]]][1]};
}

void dfs1(ar<int, 2> u) {
	if(vis1[u[0]][u[1]]) {
		cyc.push_back(u);
		return;
	}
	vis1[u[0]][u[1]]=1;
	dfs1(nxt(u));
	if(cyc.back()==nxt(u)&&cyc[0]!=u)
		cyc.push_back(u);
}

void dfs2(ar<int, 2> u, int d=0) {
	vis2[u[0]][u[1]]=1;
	if(c[u[0]][u[1]]&1^1)
		++a[d%cyc.size()];
	for(ar<int, 2> v : adj[u[0]][u[1]])
		if(!vis2[v[0]][v[1]])
			dfs2(v, d+1);
}

void solve() {
	cin >> n >> m;
	c=s=vector<string>(n);
	for(int i=0; i<n; ++i)
		cin >> c[i];
	for(int i=0; i<n; ++i)
		cin >> s[i];
	adj=vector<vector<vector<ar<int, 2>>>>(n, vector<vector<ar<int, 2>>>(m));
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j) {
			ar<int, 2> u={i, j};
			ar<int, 2> v=nxt(u);
			adj[v[0]][v[1]].push_back(u);
		}
	vis1=vis2=vector<vector<bool>>(n, vector<bool>(m));
	int a1=0, a2=0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(vis2[i][j])
				continue;
			cyc.clear();
			dfs1({i, j});
			a1+=cyc.size();
			a=vector<int>(cyc.size());
			dfs2(cyc[0]);
			for(int i=0; i<a.size(); ++i)
				a2+=a[i]>0;
		}
	}
	cout << a1 << " " << a2 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d['U']={-1, 0};
	d['R']={0, 1};
	d['D']={1, 0};
	d['L']={0, -1};
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
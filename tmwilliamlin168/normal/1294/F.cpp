#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
vector<int> adj[mxN];
ar<int, 4> ans;
ar<int, 2> d[mxN];

void dfs1(int u=0, int p=-1) {
	d[u]={1, u};
	for(int v : adj[u]) {
		if(v==p)
			continue;
		dfs1(v, u);
		d[u]=max(d[u], ar<int, 2>{d[v][0]+1, d[v][1]});
	}
}

void dfs2(int u=0, int p=-1, ar<int, 2> pd={}) {
	//cout << "d2 " << u << " " << p << " " << pd[0] << " " << pd[1] << endl;
	vector<ar<int, 2>> vd{{0, u}};
	if(pd[0])
		vd.push_back(pd);
	for(int v : adj[u]) {
		if(v==p)
			continue;
		vd.push_back(d[v]);
	}
	sort(vd.begin(), vd.end(), greater<ar<int, 2>>());
	if(vd.size()>=3) {
		ar<int, 4> ca={vd[0][0]+vd[1][0]+vd[2][0], vd[0][1], vd[1][1], vd[2][1]};
		//if(ca[0]==6)
			//cout << u << endl;
		ans=max(ca, ans);
	}
	for(int v : adj[u]) {
		if(v==p)
			continue;
		dfs2(v, u, d[v][1]==vd[0][1]?ar<int, 2>{vd[1][0]+1, vd[1][1]}:ar<int, 2>{vd[0][0]+1, vd[0][1]});
	}
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
	dfs1();
	dfs2();
	cout << ans[0] << "\n" << ans[1]+1 << " " << ans[2]+1 << " " << ans[3]+1 << "\n";
}
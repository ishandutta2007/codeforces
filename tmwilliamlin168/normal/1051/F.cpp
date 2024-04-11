#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, m, q, anc[mxN][17];
vector<array<ll, 2>> adj[mxN];
vector<array<ll, 3>> ee;
ll d1[mxN], d2[mxN], b[42][42], c1[42], c2[42];
unordered_map<int, int> mp;
vector<int> ns;

struct dsu {
	int p[mxN], r[mxN];
	void init(int n) {
		for(int i=0; i<n; ++i)
			p[i]=i;
	}
	int find(int x) {
		return x==p[x]?x:(p[x]=find(p[x]));
	}
	bool join(int x, int y) {
		if((x=find(x))==(y=find(y)))
			return 0;
		if(r[x]<r[y])
			p[x]=y;
		else
			p[y]=x;
		r[x]+=r[x]==r[y];
		return 1;
	}
} dsu;

void dfs(int u, int p) {
	anc[u][0]=p;
	for(int i=1; i<17; ++i)
		anc[u][i]=anc[u][i-1]==-1?-1:anc[anc[u][i-1]][i-1];
	for(array<ll, 2> e : adj[u]) {
		if(e[0]==p)
			continue;
		d1[e[0]]=d1[u]+e[1];
		d2[e[0]]=d2[u]+1;
		dfs(e[0], u);
	}
}

void av(int u) {
	if(mp.find(u)==mp.end()) {
		mp[u]=ns.size();
		ns.push_back(u);
	}
}

ll dist(int u, int v) {
	ll r=d1[u]+d1[v];
	if(d2[u]<d2[v])
		swap(u, v);
	for(int i=16; i>=0; --i)
		if(d2[u]-d2[v]>=1<<i)
			u=anc[u][i];
	if(u!=v) {
		for(int i=16; i>=0; --i) {
			if(anc[u][i]!=anc[v][i]) {
				u=anc[u][i];
				v=anc[v][i];
			}
		}
		u=anc[u][0];
	}
	return r-2*d1[u];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	dsu.init(n);
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		if(dsu.join(u, v)) {
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		} else
			ee.push_back({u, v, w});
	}
	dfs(0, -1);
	memset(b, 0x3f, sizeof(b));
	for(array<ll, 3> e : ee) {
		av(e[0]);
		av(e[1]);
		b[mp[e[0]]][mp[e[1]]]=b[mp[e[1]]][mp[e[0]]]=e[2];
	}
	for(int i=0; i<ns.size(); ++i)
		for(int j=i+1; j<ns.size(); ++j)
			b[i][j]=b[j][i]=min(dist(ns[i], ns[j]), b[i][j]);
	for(int k=0; k<ns.size(); ++k)
		for(int i=0; i<ns.size(); ++i)
			for(int j=0; j<ns.size(); ++j)
				b[i][j]=min(b[i][k]+b[k][j], b[i][j]);
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v, --u, --v;
		ll ans=dist(u, v);
		for(int i=0; i<ns.size(); ++i) {
			c1[i]=dist(u, ns[i]);
			c2[i]=dist(ns[i], v);
		}
		for(int i=0; i<ns.size(); ++i)
			for(int j=0; j<ns.size(); ++j)
				ans=min(c1[i]+b[i][j]+c2[j], ans);
		cout << ans << "\n";
	}
}
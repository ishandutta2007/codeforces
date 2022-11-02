#include <bits/stdc++.h>
using namespace std;

const int mxN=3e5;
int n, m, k, a[mxN], b[mxN], d[mxN], p[mxN], r[mxN], dt=1, tin[mxN], low[mxN], mdu;
bool bg[mxN];
vector<int> adj1[mxN], adj2[mxN];

int find(int x) {
	return x==p[x]?x:(p[x]=find(p[x]));
}

inline void join(int x, int y) {
	if((x=find(x))==(y=find(y)))
		return;
	if(r[x]<r[y])
		p[x]=y;
	else
		p[y]=x;
	if(r[x]==r[y])
		++r[x];
}

void dfs1(int u, int p) {
	tin[u]=low[u]=dt++;
	for(int e : adj1[u]) {
		int v=u^a[e]^b[e];
		if(!tin[v]) {
			dfs1(v, e);
			low[u]=min(low[v], low[u]);
			if(low[v]>tin[u])
				bg[e]=1;
		} else if(e!=p)
			low[u]=min(tin[v], low[u]);
	}
}

void dfs2(int u, int p) {
	d[u]=p==-1?0:d[p]+1;
	if(mdu==-1||d[u]>d[mdu])
		mdu=u;
	for(int e : adj2[u]) {
		int v=u^a[e]^b[e];
		if(v==p)
			continue;
		dfs2(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		p[i]=i;
	for(int i=0; i<m; ++i) {
		cin >> a[i] >> b[i], --a[i], --b[i];
		adj1[a[i]].push_back(i);
		adj1[b[i]].push_back(i);
	}
	dfs1(0, -1);
	for(int i=0; i<m; ++i)
		if(!bg[i])
			join(a[i], b[i]);
	for(int i=0; i<m; ++i) {
		if(!bg[i])
			continue;
		a[i]=find(a[i]);
		b[i]=find(b[i]);
		adj2[a[i]].push_back(i);
		adj2[b[i]].push_back(i);
	}
	mdu=-1;
	for(int i=0; i<n; ++i) {
		if(p[i]==i) {
			dfs2(i, -1);
			break;
		}
	}
	int u=mdu;
	mdu=-1;
	dfs2(u, -1);
	cout << d[mdu];
}
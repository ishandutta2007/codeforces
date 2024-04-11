#include <bits/stdc++.h>
using namespace std;

const int mxN=5e4, mxlgA=16, m1=1<<8, m2=1<<mxlgA;
int n, q, a[mxN], p1[mxN], p2[mxN], dep[mxN], mv[mxN][m2/m1], trie[mxlgA*m1][2], ts;
vector<int> adj[mxN];

inline void initTrie() {
	memset(trie, 0, sizeof(trie));
	ts=1;
}

inline void ins(int x) {
	for(int i=mxlgA-1, c=0; i>=0; --i) {
		int b=x>>i&1;
		if(!trie[c][b])
			trie[c][b]=ts++;
		c=trie[c][b];
	}
}

inline int qry(int x) {
	for(int i=mxlgA-1, c=0; i>=0; --i) {
		int b=x>>i&1^1;
		if(!trie[c][b])
			b^=1;
		x^=b<<i;
		c=trie[c][b];
	}
	return x;
}

void dfs1(int u) {
	for(int v : adj[u]) {
		if(v==p1[u])
			continue;
		p1[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	p1[0]=-1;
	dfs1(0);
	for(int i=0; i<n; ++i) {
		p2[i]=i;
		initTrie();
		for(int j=0; j<m1&&p2[i]!=-1; p2[i]=p1[p2[i]], ++j)
			ins(a[p2[i]]^j);
		for(int j=0; j*m1<m2; ++j)
			mv[i][j]=qry(j*m1);
//		cout << p1[i] << " " << p2[i] << endl;
	}
	while(q--) {
		int u, v, ans=0, i;
		cin >> u >> v, --u, --v;
		for(i=0; p2[v]!=-1&&dep[p2[v]]-1>=dep[u]; v=p2[v], ++i)
			ans=max(mv[v][i], ans);
//		cout << "h1 " << v << endl;
		for(i*=m1; v!=-1&&dep[v]>=dep[u]; v=p1[v], ++i)
			ans=max(a[v]^i, ans);
		cout << ans << "\n";
	}
}
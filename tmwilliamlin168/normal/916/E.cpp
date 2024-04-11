#include <bits/stdc++.h>
using namespace std;

#define ll long long

inline int lg2(int x) {
	return 31-__builtin_clz(x);
}

const int mxN=1e5;
vector<int> graph[mxN];
int n, q, a[mxN], qt, rt, anct[17][mxN], dep[mxN], st[mxN], en[mxN], dt;
ll fta[mxN+1], ftb[mxN+1], ans;

inline void add(int l, ll x) {
	for(int i=l+1; i<=n; i+=i&-i) {
		fta[i]+=x*(n-l);
		ftb[i]+=x;
	}
}

inline ll sum(int r) {
	ll ta=0, tb=0;
	for(int i=r; i; i-=i&-i) {
		ta+=fta[i];
		tb+=ftb[i];
	}
	return ta-tb*(n-r);
}

void dfs1(int u, int p) {
	anct[0][u]=p;
	dep[u]=p==-1?0:dep[p]+1;
	st[u]=dt++;
	add(st[u], a[u]);
	add(st[u]+1, -a[u]);
	for(int v : graph[u])
		if(v!=p)
			dfs1(v, u);
	en[u]=dt;
}

inline int anc(int u, int d) {
	for(int i=0; i<=lg2(n); ++i)
		if((d>>i)&1)
			u=anct[i][u];
	return u;
}

inline int lca(int u, int v) {
	if(dep[u]<dep[v])
		swap(u, v);
	u=anc(u, dep[u]-dep[v]);
	if(u==v)
		return u;
	for(int i=lg2(n); i>=0; --i)
		if(anct[i][u]!=anct[i][v])
			u=anct[i][u], v=anct[i][v];
	return anct[0][u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs1(0, -1);
	for(int i=1; i<=lg2(n); ++i)
		for(int j=0; j<n; ++j)
			anct[i][j]=anct[i-1][j]==-1?-1:anct[i-1][anct[i-1][j]];
	while(q--) {
		cin >> qt;
		if(qt==1) {
			cin >> rt;
			--rt;
		} else if(qt==2) {
			int u, v, x;
			cin >> u >> v >> x;
			--u, --v;
			int luv=lca(u, v), lur=lca(u, rt), lvr=lca(v, rt);
			if(lur!=luv&&lvr!=luv) {
				add(st[luv], x);
				add(en[luv], -x);
			} else {
				add(0, x);
				if(lur!=rt&&lvr!=rt) {
					int w=lur!=luv?lur:lvr;
					w=anc(rt, dep[rt]-dep[w]-1);
					add(st[w], -x);
					add(en[w], x);
				}
			}
		} else {
			int v;
			cin >> v;
			--v;
			if(v==rt)
				ans=sum(n);
			else if(st[v]<st[rt]&&st[rt]<en[v]) {
				int w=anc(rt, dep[rt]-dep[v]-1);
				ans=sum(n)-(sum(en[w])-sum(st[w]));
			} else
				ans=sum(en[v])-sum(st[v]);
			cout << ans << "\n";
		}
	}
}
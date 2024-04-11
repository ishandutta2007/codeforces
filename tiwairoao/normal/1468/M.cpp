#include <bits/stdc++.h>

const int N = 500000;

int read() {
	int x = 0, ch = getchar();
	while( ch > '9' || ch < '0' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10 * x + ch - '0', ch = getchar();
	return x;
}

std::map<int, int>mp;
int deg[N + 5], n, m, c;
int tag[N + 5], u[N + 5], v[N + 5];
std::vector<int>G[N + 5], G2[N + 5];

int id(int x) {
	if( !mp.count(x) ) {
		int k = (++m); mp[x] = k;
		deg[k] = tag[k] = 0, G[k].clear(), G2[k].clear();
		return k;
	}
	return mp[x];
}

void solve() {
	n = read(), m = n, c = 0, mp.clear();
	for(int i=1;i<=n;i++) deg[i] = tag[i] = 0, G[i].clear(), G2[i].clear();
	for(int i=1,k;i<=n;i++) {
		k = read();
		for(int j=1;j<=k;j++) {
			c++, u[c] = i, v[c] = id(read());
			G2[u[c]].push_back(v[c]), deg[u[c]]++;
			G2[v[c]].push_back(u[c]), deg[v[c]]++;
		}
	}
	for(int i=1;i<=c;i++) {
		if( deg[u[i]] < deg[v[i]] ) std::swap(u[i], v[i]);
		G[u[i]].push_back(v[i]);
	}
	for(int i=1;i<=m;i++) {
		for(auto x : G[i]) for(auto y : G2[x]) if( y != i ) {
			if( tag[y] ) {
				if( i <= n ) printf("%d %d\n", i, y);
				else printf("%d %d\n", x, tag[y]);
				return ;
			} else tag[y] = x;
		}
		for(auto x : G[i]) for(auto y : G2[x]) if( y != i ) tag[y] = 0;
	}
	puts("-1");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
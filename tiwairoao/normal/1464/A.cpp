#include <bits/stdc++.h>

const int N = 100000;

int fa[N + 5];
int find(int x) {return fa[x] = (fa[x] == x ? x : find(fa[x]));}
bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) {
		fa[fx] = fy;
		return true;
	} else return false;
}

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) fa[i] = i;
	
	int ans = m;
	for(int i=1,u,v;i<=m;i++) {
		scanf("%d%d", &u, &v);
		if( u == v ) ans--;
		else if( !unite(u, v) ) ans++;
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
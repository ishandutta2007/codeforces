#include <bits/stdc++.h>

const int N = 100000;

std::vector<int>v[N + 5];

int ans[N + 5], c[N + 5], n, m, l;

void solve() {
	scanf("%d%d", &n, &m), l = (m + 1) >> 1;
	for(int i=1;i<=n;i++) c[i] = 0;
	for(int i=1,k;i<=m;i++) {
		scanf("%d", &k), v[i].clear();
		for(int j=0,x;j<k;j++) scanf("%d", &x), v[i].push_back(x);
		if( k == 1 ) c[v[i][0]]++;
	}
	for(int i=1;i<=n;i++) if( c[i] > l ) {puts("NO"); return ;}
	for(int i=1;i<=m;i++) if( v[i].size() != 1 ) {
		if( c[v[i][0]] == l ) ans[i] = v[i][1], c[ans[i]]++;
		else ans[i] = v[i][0], c[ans[i]]++;
	} else ans[i] = v[i][0];
	puts("YES"); for(int i=1;i<=m;i++) printf("%d ", ans[i]); puts("");
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}
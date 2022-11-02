#include <bits/stdc++.h>

int a[105];

void solve() {
	int n, u, v; scanf("%d%d%d", &n, &u, &v);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	
	for(int i=1;i<n;i++) if( a[i] - a[i + 1] > 1 || a[i] - a[i + 1] < -1 ) {
		puts("0"); return ;
	}
	for(int i=1;i<n;i++) if( a[i] != a[i + 1] ) {
		printf("%d\n", std::min(u, v)); return ;
	}
	printf("%d\n", std::min(u, v) + v);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
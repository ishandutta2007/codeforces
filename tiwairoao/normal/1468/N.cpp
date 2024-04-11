#include <bits/stdc++.h>

int c[3], a[5];

void solve() {
	for(int i=0;i<3;i++) scanf("%d", &c[i]);
	for(int i=0;i<5;i++) scanf("%d", &a[i]);
	for(int i=0;i<3;i++) {
		c[i] -= a[i];
		if( c[i] < 0 ) {puts("NO"); return ;}
	}
	
	a[3] -= c[0]; if( a[3] >= 0 ) c[2] -= a[3];	
	a[4] -= c[1]; if( a[4] >= 0 ) c[2] -= a[4];
	puts(c[2] >= 0 ? "YES" : "NO");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
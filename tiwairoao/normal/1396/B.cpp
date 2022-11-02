#include <bits/stdc++.h>

int a[105], n;

void solve() {
	int s = 0; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), s += a[i];
	std::sort(a + 1, a + n + 1);
	
	puts( 2 * a[n] > s || (s & 1) ? "T" : "HL");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
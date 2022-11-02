#include <bits/stdc++.h>

const int N = 200000;

int a[N + 5];

int solve(int l, int r, int d) {
	if( l == r ) return 0;
	
	int m = l - 1;
	for(int i=l;i<=r;i++) if( !((a[i] >> d) & 1) )
		m = i;
	
	if( m < l ) return solve(m + 1, r, d - 1);
	else if( m + 1 > r ) return solve(l, m, d - 1);
	else {
		int p = solve(l, m, d - 1), q = solve(m + 1, r, d - 1);
		return std::min(p + (r - m - 1), q + (m - l));
	}
}

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	printf("%d\n", solve(1, n, 30));
}
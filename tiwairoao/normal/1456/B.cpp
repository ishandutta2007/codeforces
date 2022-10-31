#include <bits/stdc++.h>

const int N = int(1E5);

int bits(int x) {
	int p = 0;
	while( x ) x >>= 1, p++;
	return p;
}

int a[N + 5], b[N + 5], n;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), b[i] = bits(a[i]);
	for(int i=2;i<n;i++) if( b[i] == b[i - 1] && b[i] == b[i + 1] ) {
		puts("1"); return 0;
	}
	
	int ans = n + 1;
	for(int i=1;i<n;i++) {
		int p = 0;
		for(int j=i;j>=1;j--) {
			p ^= a[j]; int q = 0;
			for(int k=i+1;k<=n;k++) {
				q ^= a[k];
				if( p > q ) {
					ans = std::min(ans, i - j + k - i - 1);
				}
			}
		}
	}
	printf("%d\n", ans == n + 1 ? -1 : ans);
}
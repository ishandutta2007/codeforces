#include <bits/stdc++.h>

const int N = 100000;

int l1[N + 5], r1[N + 5], l2[N + 5], r2[N + 5], p[N + 5], n;

int main() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%d", &p[i]);
	for(int i=2;i<=n;i++) {
		if( p[i - 1] < p[i] ) l1[i] = l1[i - 1] + 1;
		else l2[i] = l2[i - 1] + 1;
	}
	for(int i=n-1;i>=1;i--) {
		if( p[i] > p[i + 1] ) r1[i] = r1[i + 1] + 1;
		else r2[i] = r2[i + 1] + 1;
	}
	
	int mx = 0, cnt = 0;
	for(int i=1;i<=n;i++) mx = std::max(mx, r1[i]);
	for(int i=1;i<=n;i++) if( l1[i] == mx ) cnt++;
	for(int i=1;i<=n;i++) if( r1[i] == mx ) cnt++;
	
	int ans = 0;
	for(int i=1;i<=n;i++) if( l1[i] && r1[i] ) {
		int tmp = (l1[i] == mx) + (r1[i] == mx);
		if( tmp == cnt && cnt == 2 && !(mx & 1) ) ans++;
	}
	printf("%d\n", ans);
}
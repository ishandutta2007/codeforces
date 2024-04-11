#include <bits/stdc++.h>

const int N = 100000;

int cnt[2], a[N + 5];

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), cnt[a[i]]++;
	for(int i=1,t,x;i<=q;i++) {
		scanf("%d%d", &t, &x);
		if( t == 1 ) cnt[a[x]]--, cnt[a[x] ^= 1]++;
		else {
			printf("%d\n", x <= cnt[1] ? 1 : 0);
		}
	}
}
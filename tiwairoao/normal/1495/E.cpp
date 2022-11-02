#include <bits/stdc++.h>

typedef unsigned long long ull;

const int M = 200000;
const int N = 5000000;
const int P = int(1E9) + 7;

int p[M + 5], k[M + 5], b[M + 5], w[M + 5];

int a[N + 5], t[N + 5], n, m;

int seed = 0, base = 0;
int rnd() {
	int ret = seed;
	seed = ((ull)seed * base + 233) % P;
	return ret;
}

void gen() {
	p[0] = 0;
	for(int i=1;i<=m;i++) {
		seed = b[i], base = w[i];
		for(int j=p[i-1]+1;j<=p[i];j++) {
			t[j] = (rnd() % 2);
			a[j] = (rnd() % k[i]) + 1;
		}
	}
}

int c[N + 5], o; ull tot;
void iter(int x) {
	for(int i=x,j=1;j<=n;i=(i+1>n?1:i+1),j++) {
		if( t[i] == o ) tot += a[i], c[i] += a[i], a[i] = 0;
		else if( tot > a[i] ) tot -= a[i], c[i] += a[i], a[i] = 0;
		else c[i] += tot, a[i] -= tot, tot = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) scanf("%d%d%d%d", &p[i], &k[i], &b[i], &w[i]);
	gen();
	
	ull cnt[2] = {}; for(int i=1;i<=n;i++) cnt[t[i]] += a[i];
	
	int x = 1;
	if( cnt[t[1]] > cnt[t[1] ^ 1] ) {
		a[1]--, c[1]++;
		while( x <= n && t[x] == t[1] ) x++;
		o = t[1] ^ 1;
	} else o = t[1];
	
	if( x <= n ) iter(1), iter(1);
	
	int ans = 1;
	for(int i=1;i<=n;i++) {
		ans = (ull)ans * ((((ull)i * i) ^ c[i]) % P + 1) % P;
	}
	printf("%d\n", ans);
}
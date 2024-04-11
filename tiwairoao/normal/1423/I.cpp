#include <bits/stdc++.h>

const int N = 200000;

int k, t, q;

int st[2][20][1 << 16], lg[(1 << 16) + 5];
void init() {
	for(int i=2;i<=t+1;i++) lg[i] = lg[i >> 1] + 1;
}
void update(int o, int l, int r, int d) {
	int p = lg[r - l + 1];
	st[o][p][l] |= d, st[o][p][r - (1 << p) + 1] |= d;
}
void build() {
	for(int i=k,l=(1<<(i-1));i>=1;i--,l>>=1) {
		for(int j=0;j+l<=t;j++) {
			st[0][i - 1][j] |= st[0][i][j], st[0][i - 1][j + l] |= st[0][i][j];
			st[1][i - 1][j] |= st[1][i][j], st[1][i - 1][j + l] |= st[1][i][j];
		}
	}
	
	for(int i=1,l=(1<<(i-1));i<=k;i++,l<<=1) {
		for(int j=0;j+l<=t;j++) {
			st[0][i][j] = (st[0][i - 1][j] | st[0][i - 1][j + l]);
			st[1][i][j] = (st[1][i - 1][j] | st[1][i - 1][j + l]);
		}
	}
}
int query(int o, int l, int r) {
	int p = lg[r - l + 1];
	return st[o][p][l] | st[o][p][r - (1 << p) + 1];
}

unsigned l[N + 5], r[N + 5]; int v[N + 5];

int main() {
	scanf("%d%d", &k, &q), t = (1 << k) - 1, init();
	for(int i=1;i<=q;i++) {
		scanf("%u%u%d", &l[i], &r[i], &v[i]);
		if( (l[i] >> k) == (r[i] >> k) ) update(0, l[i] & t, r[i] & t, v[i]);
		else if( r[i] - l[i] + 1 >= t ) update(0, 0, t, v[i]);
		else update(0, l[i] & t, t, v[i]), update(0, 0, r[i] & t, v[i]);
		update(1, l[i] >> k, r[i] >> k, v[i]);
	}
	build();
	
	for(int i=1;i<=q;i++) {
		int le = (l[i] >> k), ri = (r[i] >> k);
		if( le == ri ) {
			if( (query(1, le, ri) & query(0, l[i] & t, r[i] & t)) != v[i] )
				{puts("impossible"); return 0;}
		} else {
			if( (query(1, le, le) & query(0, l[i] & t, t)) != v[i] )
				{puts("impossible"); return 0;}
			if( (query(1, ri, ri) & query(0, 0, r[i] & t)) != v[i] )
				{puts("impossible"); return 0;}
			if( le + 1 <= ri - 1 && (query(1, le + 1, ri - 1) & query(0, 0, t)) != v[i] )
				{puts("impossible"); return 0;}
		}
	}
	
	puts("possible");
	for(int i=0;i<=t;i++) printf("%d\n", st[0][0][i]);
	for(int i=0;i<=t;i++) printf("%d\n", st[1][0][i]);
}
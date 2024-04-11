#include <bits/stdc++.h>

const int N = 50;
const int S = 2000;
const int P = 998244353;

inline int add(int x, int y) {return (x + y >= P ? x + y - P : x + y);}
inline int sub(int x, int y) {return (x - y < 0 ? x - y + P : x - y);}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}
int mpow(int b, int p) {
	int r = 1; for(; p; p >>= 1, b = mul(b, b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

int fct[S + 5], ifct[S + 5];
void init() {
	fct[0] = 1; for(int i=1;i<=S;i++) fct[i] = mul(fct[i - 1], i);
	ifct[S] = mpow(fct[S], P - 2); for(int i=S-1;i>=0;i--) ifct[i] = mul(ifct[i + 1], i + 1);
}

int l[N + 5], s, n, k, L;
int f[N + 5][S + 5], g[N + 5][S + 5], q[N + 5][S + 5];

void solve() {
	s = 0, q[0][0] = 1;
	for(int i=1;i<=n;i++) {
		if( l[i] <= k ) continue;
		
		int t = (l[i] / k);
		for(int j=i;j>=0;j--) {
			if( j != i ) {
				for(int x=s+t;x>=0;x--) {
					q[j][x] = mul(q[j][x], f[i][0]);
					for(int y=1;y<=t&&y<=x;y++)
						q[j][x] = add(q[j][x], mul(q[j][x - y], f[i][y]));
				}
			}
			
			if( j != 0 ) {
				for(int x=s+t;x>=0;x--) for(int y=0;y<=t&&y<=x;y++)
					q[j][x] = add(q[j][x], mul(q[j - 1][x - y], g[i][y]));
			}
		}
		s += t;
	}
}
int main() {
	scanf("%d%d", &n, &k), init();
	for(int i=1;i<=n;i++) scanf("%d", &l[i]), L += l[i];
	
	int ivL = mpow(L, P - 2);
	for(int i=1;i<=n;i++) {
		int u = l[i] / k;
		for(int t=0;t<=u;t++) {
			f[i][t] = mul(ifct[t], mpow(mul(l[i] - k * t, ivL), t));
			if( t & 1 ) f[i][t] = sub(0, f[i][t]);
		}
		for(int t=0;t<u;t++) {
			g[i][t] = mul(ifct[t], mpow(mul(l[i] - k * t - k, ivL), t));
			if( !(t & 1) ) g[i][t] = sub(0, g[i][t]);
		}
	}
	
	solve();
	
	int ans = 0; q[0][0] = sub(q[0][0], 1);
	for(int j=0;j<=n;j++) for(int i=0;i<=s;i++) if( q[j][i] ) {
		int A = sub(1, mul(k * (i + j), ivL));
		ans = sub(ans, mul(mul(fct[i], mpow(sub(1, A), (P - 1) - (i + 1))), q[j][i]));
	}
	printf("%d\n", ans);
}
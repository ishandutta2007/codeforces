#include <bits/stdc++.h>

const int S = 1500;
const int P = int(1E9) + 7;

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {if( x == 0 || y == 0 ) return 0; else return (int)(1ll * x * y % P);}
int mpow(int b, int p) {
	int r; for(r = 1; p; p >>= 1, b = mul(b, b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

int comb[45][45], fct[45];
void init() {
	fct[0] = 1; for(int i=1;i<=40;i++) fct[i] = mul(fct[i - 1], i);
	for(int i=0;i<=40;i++) for(int j=0;j<=i;j++)
		comb[i][j] = (j == 0 ? 1 : add(comb[i - 1][j], comb[i - 1][j - 1]));
}

/*
int mx = 0;
void divide(int n, int x, int s) {
	if( n == 0 ) {
		mx = std::max(mx, s);
		return ;
	}
	if( n < x ) return ;
	for(int p=0;p*x<=n;p++)
		divide(n - p * x, x + 1, s * (p + 1));
}
void calc() {
	divide(40, 1, 1);
	printf("%d\n", mx);
}
*/

int a[45], n, t;

int g[45][45], sz[S + 5], sum[S + 5];
void pre() {
	t = 1; for(int i=1;i<=n;i++) t = t * a[i];
	for(int i=0;i<t;i++) for(int k=1,i1=i;k<=n;i1/=a[k],k++)
		sz[i] += (i1 % a[k]), sum[i] += (i1 % a[k]) * k;
	
	int h[45] = {};
	for(int j=0;j<=n;j++) for(int p=0;p<=j;p++)
		h[j] = add(h[j], mul(comb[j][p], mul(fct[p], fct[n - p - 1])));
	
	for(int j=0;j<=n;j++) {
		g[0][j] = 1;
		for(int i=1;i<=n;i++)
			g[i][j] = mul(g[i - 1][j], h[j]);
	}
}

int calc(int i, int j) {
	int ans = 1;
	for(int k=1,i1=i,j1=j;k<=n;i1/=a[k],j1/=a[k],k++)
		ans = mul(ans, comb[i1 % a[k]][j1 % a[k]]);
	ans = mul(ans, g[sum[j]][sum[i - j]]);
	return sz[j] & 1 ? ans : sub(0, ans);
}

int f[S + 5];
void solve() {
	f[t - 1] = 1;
	for(int i=t-1;i>0;i--) for(int j=i;j>0;j--)
		f[i - j] = add(f[i - j], mul(f[i], calc(i, j)));
}

int p[45], vis[45];
int main() {
//	calc();
	init(), scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &p[i]), a[i]++;
	for(int i=1;i<=n;i++) if( !vis[i] ) {
		int tmp = i, s = 0;
		do {
			vis[tmp] = true, tmp = p[tmp], s++;
		}while( !vis[tmp] );
		a[s]++;
	}
	pre(), solve(), printf("%d\n", f[0]);
}
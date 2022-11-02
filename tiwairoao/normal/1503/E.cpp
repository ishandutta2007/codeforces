#include <bits/stdc++.h>

typedef long long ll;

const int P = 998244353;
const int N = 2077;

int norm(int x) {if( x >= P ) x -= P; return x;}
int reduce(int x) {if( x < 0 ) x += P; return x;}
void add(int &x, int y) {if( (x += y) >= P ) x -= P;}
void sub(int &x, int y) {if( (x -= y) < 0 ) x += P;}

int c[2*N + 5][2*N + 5];
void init() {
	for(int i=0;i<=2*N;i++) for(int j=0;j<=i;j++)
		c[i][j] = (j == 0 ? 1 : norm(c[i - 1][j] + c[i - 1][j - 1]));
}

int a[N + 5], b[N + 5], n, m;
int solve() {
	int ret = 0;
	
	for(int i=1;i<n;i++) {
		for(int j=1;j<=m;j++) {
			a[j] = (ll)c[i + j - 1][i] * c[i - 1 + m - j][i - 1] % P;
		}
		for(int j=1;j<=m;j++) {
			b[j] = (ll)c[n - i + j - 1][n - i] * c[n - i + m - j - 1][n - i - 1] % P;
			add(b[j], b[j - 1]);
		}
		
		for(int j=1;j<m;j++) add(ret, (ll)a[j] * b[m - j] % P);
	}
	
	std::swap(n, m);
	for(int i=1;i<n;i++) {
		for(int j=1;j<=m;j++) {
			a[j] = (ll)c[i + j - 1][i] * c[i - 1 + m - j][i - 1] % P;
		}
		for(int j=1;j<=m;j++) {
			b[j] = (ll)c[n - i + j - 1][n - i] * c[n - i + m - j - 1][n - i - 1] % P;
			add(b[j], b[j - 1]);
		}
		
		for(int j=2;j<m;j++) add(ret, (ll)a[j - 1] * b[m - j] % P);
	}
	
	return norm(ret + ret);
}

int main() {
	init(), scanf("%d%d", &n, &m), printf("%d\n", solve());
}
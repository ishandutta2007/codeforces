#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int k;
int mod(1e9 + 7);
int a[99], b[99], c[99];
int f[32][2][2][2], g[32][2][2][2];
inline void inc(int & x, int y) {
	if((x += y) >= mod) x -= mod;
}
int calc(int lim1, int lim2) {
	
	if(!lim1 || !lim2) return 0;
	lim1--; lim2--;
	int lim3(k - 1);
	for(int i(0); i <= 31; i++) {
		a[i] = lim1 >> i & 1;
		b[i] = lim2 >> i & 1;
		c[i] = lim3 >> i & 1;
	}
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	f[31][1][1][1] = 0;
	g[31][1][1][1] = 1;
	for(int i(31); i >= 1; i--)
		for(int j(0); j < 2; j++)
			for(int k(0); k < 2; k++)
				for(int l(0); l < 2; l++)
					if(g[i][j][k][l])
						for(int m(0); m < 2; m++)
							for(int n(0); n < 2; n++) {
								if(j == 1 && m > a[i - 1] || k == 1 && n > b[i - 1] || l == 1 && ((n ^ m) > c[i - 1])) continue;
								inc(g[i - 1][j == 1 && m == a[i - 1]][k == 1 && n == b[i - 1]][l == 1 && ((n ^ m) == c[i - 1])], g[i][j][k][l]);
								inc(f[i - 1][j == 1 && m == a[i - 1]][k == 1 && n == b[i - 1]][l == 1 && ((n ^ m) == c[i - 1])], (f[i][j][k][l] * 2ll + g[i][j][k][l] * (n ^ m)) % mod);
							}
	int res(0);
	for(int j(0); j < 2; j++)
		for(int k(0); k < 2; k++)
			for(int l(0); l < 2; l++)
				inc(res, (g[0][j][k][l] + f[0][j][k][l]) % mod);
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int qq(1); qq <= t; qq++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
		printf("%I64d\n", ((LL)calc(x2, y2) - calc(x1 - 1, y2) - calc(x2, y1 - 1) + calc(x1 - 1, y1 - 1) + 2 * mod) % mod);
	}
}
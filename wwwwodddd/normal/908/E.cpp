#include <bits/stdc++.h>
using namespace std;
int f[1020];
int c[1020];
long long a[1020][1020];
int p = 1000000007;
char s[52][1020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < m; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) {
			bool allsame = true;
			for (int k = 0; k < n; k++) {
				if (s[k][i] != s[k][j]) {
					allsame = false;
					break;
				}
			}
			if (allsame) {
				U(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		c[F(i)]++;
	}
	a[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			a[i][j] = (j * a[i - 1][j] + a[i - 1][j - 1]) % p;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			a[i][0] = (a[i][0] + a[i][j]) % p;
		}
	}
	long long z = 1;
	for (int i = 0; i < m; i++) {
		if (c[i] > 0) {
			z = z * a[c[i]][0] % p;
		}
	}
	printf("%lld\n", z);
	return 0;
}
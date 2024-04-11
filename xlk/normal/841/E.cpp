#include <bits/stdc++.h>
using namespace std;
int n, x, p = 1000000007;
int b[320], cnt;
int c[320][320];
int f[320][320];
map<int, int> g;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int i = 2; i * i <= x; i++) {
			while (x % (i * i) == 0) {
				x /= i * i;
			}
		}
		g[x]++;
	}
//	for (pair<int, int> i: g) {
//		printf("%d %d\n", i.first, i.second);
//	}
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	for (pair<int, int> i: g) {
		b[cnt++] = i.second;
	}
	f[0][0] = 1;
	int tot = 0; 
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j <= tot; j++) {
			if (f[i][j] == 0) {
				continue;
			}
			for (int k = 1; k <= min(b[i], tot + 1); k++) {
				for (int l = 0; l <= min(j, k); l++) {
					int &t = f[i + 1][j - l + b[i] - k];
					long long d = f[i][j];
					d = (d * c[b[i] - 1][k - 1]) % p;
					d = (d * c[j][l]) % p;
					d = (d * c[tot - j + 1][k - l]) % p;
					t = (t + d) % p;
				}
			}
		}
		tot += b[i];
	}
	int z = f[cnt][0];
	for (pair<int, int> i: g) {
		for (int j = 1; j <= i.second; j++) {
			z = (long long)z * j % p;
		}
	}
	printf("%d\n", z);
	return 0;
}
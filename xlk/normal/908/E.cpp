#include <bits/stdc++.h>
using namespace std;
int n, m, p = 1000000007;
long long a[1020];
int b[1020];
int c[1020][1020];
char s[1020];
map<long long, int> g;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++) {
			a[j] = a[j] * 2 + s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		g[a[i]]++;
	}
	b[0] = 1;
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
		for (int j = 0; j <= i; j++) {
			b[i + 1] = (b[i + 1] + (long long)b[j] * c[i][j]) % p;
		}
	}
	int z = 1;
	for (auto i: g) {
		z = (long long)z * b[i.second] % p;
	}
	printf("%d\n", z);
	return 0;
}
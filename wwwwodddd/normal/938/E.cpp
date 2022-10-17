#include <bits/stdc++.h>
using namespace std;
int n, x, p = 1000000007;
map<int, int> g;
int v[1000020];
int f[1000020];
long long z = 0;
int main() {
	scanf("%d", &n);
	v[0] = v[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = (long long)f[i - 1] * i % p;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		g[x]++;
	}
	long long z = 0, c = n;
	for (pair<int, int> i: g) {
		if (c == i.second) {
			break;
		}
		z = (z + (long long)f[n] * i.second % p * i.first % p * v[c] % p) % p;
		c -= i.second;
	}
	printf("%lld\n", z);
	return 0;
}
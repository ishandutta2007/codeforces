#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, x, z, p = 1000000007;
ll f[51][51][51];
void add(ll &x, ll y, ll z) {
	x = (x + y * z) % p;
}
int main() {
	cin >> n >> m;
	f[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= i; k++) {
				if (f[i][j][k] > 0) {
					if (x != 1) {
						if (k == 0) {
							add(f[i + 1][j + 1][k], f[i][j][k], (1LL << i) % p);
						} else {
							add(f[i + 1][j + 1][k], f[i][j][k], (1LL << (i - 1)) % p);
							add(f[i + 1][j][k], f[i][j][k], (1LL << (i - 1)) % p);
						}
					}
					if (x != 0) {
						if (j == 0) {
							add(f[i + 1][j][k + 1], f[i][j][k], (1LL << i) % p);
						} else {
							add(f[i + 1][j][k + 1], f[i][j][k], (1LL << (i - 1)) % p);
							add(f[i + 1][j][k], f[i][j][k], (1LL << (i - 1)) % p);
						}
					}
				}
			}
		}
	}
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= n; k++) {
			if ((j + k + m) % 2 == 0) {
				z = (z + f[n][j][k]) % p;
			}
		}
	}
	cout << z << endl;
	return 0;
}
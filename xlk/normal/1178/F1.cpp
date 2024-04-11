#include <bits/stdc++.h>
using namespace std;
int f[520][520];
int c[520];
int n, m, mod = 998244353;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i <= n; i++) {
		f[i + 1][i] = 1;
	}
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i + l - 1 <= n; i++) {
			int j = i + l - 1;
			int left = 0;
			int right = 0;
			int minc = n + 1;
			int mini = -1;
			for (int k = i; k <= j; k++) {
				if (minc > c[k]) {
					minc = c[k];
					mini = k;
				}
			}
			for (int k = i; k <= mini; k++) {
				left = (left + (long long)f[i][k-1] * f[k][mini-1]) % mod;
			}
			for (int k = mini; k <= j; k++) {
				right = (right + (long long)f[mini+1][k] * f[k+1][j]) % mod;
			}
			f[i][j] = (long long)left * right % mod;
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}
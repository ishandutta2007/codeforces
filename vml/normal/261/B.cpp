//#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

const int maxn = 55;
int n;
int v[maxn];
long double dp[2][maxn][maxn][maxn][maxn];
long double fact[maxn];

int main() {
	fact[0] = 1;

	for (int i = 1; i < maxn; i++) {
		fact[i] = fact[i - 1] * i;
	}

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		//v[i] = 1;
	}

	int p;

	scanf("%d", &p);

	int it = 0;

	for (int i = 0; i <= p; i++) {
		dp[1][0][0][i][0] = 1;
	}

	for (int pos = n - 1; pos >= 0; pos--) {
		int nit = ((it + 1) & 1);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= p; j++) {
				for (int k = 0; k <= p; k++) {
					for (int t = 0; t <= n - i; t++) {
						dp[it][i][j][k][t] = 0;
						if (i != 0 && v[pos] <= j) {
							dp[it][i][j][k][t] += dp[nit][i - 1][j - v[pos]][k][t];
						}

						if (v[pos] <= k) {
							dp[it][i][j][k][t] += dp[nit][i][j][k][t];
						} else if (t > 0) {
							dp[it][i][j][k][t] += dp[nit][i][j][k][t - 1];
						}
					}
				}
			}
		}

		it = nit;
	}

	it = ((it + 1) & 1);

	long double ans = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= p; j++) {
			for (int t = 0; t <= n - i; t++) {
				//cout << i << ' ' << j << ' ' << p - j << ' ' << t << ' ' << dp[it][i][j][p - j][t] << endl;
				if (t != 0 || (t == 0 && i == n)) {
					if (t != 0) {
						ans += dp[it][i][j][p - j][t] * fact[i] * t * fact[n - i - 1] * i;
					} else {
						ans += dp[it][i][j][p - j][t] * fact[i] * i;
					}
				}
			}
		}
	}

	printf("%.10Lf", ans / fact[n]);

	return 0;
}
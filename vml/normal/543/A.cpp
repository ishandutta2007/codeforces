#pragma comment (linker, "/STACK:1000000000")

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
#include <unordered_map>

using namespace std;

const int maxn = 510;

int dp[2][maxn][maxn];
int v[maxn];

int main() {
	int n, m, b, mod;

	scanf("%d %d %d %d", &n, &m, &b, &mod);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int it = 1;
	
	for (int i = 0; i <= b; i++) {
		dp[0][0][i] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int nit = (it + 1) & 1;

		for (int j = 0; j <= m; j++) {
			for (int t = 0; t <= b; t++) {
				if (j == 0 || t < v[i]) {
					dp[it][j][t] = dp[nit][j][t];
				} else {
					dp[it][j][t] = dp[nit][j][t] + dp[it][j - 1][t - v[i]];
					dp[it][j][t] %= mod;
				}
			}
		}

		it = nit;
	}

	it = (it + 1) & 1;

	cout << dp[it][m][b] << endl;

	return 0;
}
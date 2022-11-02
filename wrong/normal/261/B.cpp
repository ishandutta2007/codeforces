#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long Int;

Int dp[64][64][64][64];
double fact[64];

int main()
{
	int n, a[64], p, s = 0;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}

	cin >> p;

	if (s <= p) {
		printf("%.9f\n", (double)n);
		return 0;
	}

	fact[0] = 1;
	for (int i = 1; i < 64; ++i) {
		fact[i] = fact[i - 1] * i;
	}

	for (int ignore = 0; ignore < n; ++ignore) {
		dp[ignore][0][0][0] = 1;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				for (int k = 0; k <= p; ++k) {
					if (i != ignore && k + a[i] <= p) {
						dp[ignore][i + 1][j + 1][k + a[i]] += dp[ignore][i][j][k];
					}
					dp[ignore][i + 1][j][k] += dp[ignore][i][j][k];
				}
			}
		}
	}

	double res = 0;
	for (int cnt = 1; cnt < n; ++cnt) {
		Int pats = 0;

		for (int last = 0; last < n; ++last) {
			for (int w = max(0, p - a[last] + 1); w <= p; ++w) {
				pats += dp[last][n][cnt][w];
			}
		}

		res += cnt * (double)pats * fact[cnt] * fact[n - cnt - 1] / fact[n];
	}

	printf("%.9f\n", res);

	return 0;
}
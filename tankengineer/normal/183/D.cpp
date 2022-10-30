#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 3005, M = 305;

int n, m;
double p[N][M], dp[M][N];

void calnext(const int i) {
	for (int j = 0; j < n; ++j) {
		dp[i][j + 1] += dp[i][j] * (1 - p[j + 1][i]);
	}
	double sum = 0;
	for (int j = n; j >= 1; --j) {
		sum += (dp[i][j] = dp[i][j - 1] * p[j][i]);
	}
	dp[i][0] = 0;
	dp[i][n] = sum;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%lf", &p[i][j]);
			p[i][j] /= 1000;
		}
	}
	for (int i = 1; i <= m; ++i) {
		dp[i][0] = 1;
		calnext(i);
	}
	double ans = 0;
	int best;
	for (int i = 1; i <= n; ++i) {
		best = 1;
		for (int j = 1; j <= m; ++j) {
//cout << j << ' ' << dp[j][n] << endl;
			if (dp[j][n] > dp[best][n]) best = j;
		}
		ans += dp[best][n];
//cout << best << ' ' << ans << endl;
		calnext(best);
	}
	printf("%.12lf\n", ans);
	return 0;
}
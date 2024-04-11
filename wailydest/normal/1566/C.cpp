#include <cstdio>
#include <algorithm>

const int INF = 1000000000;

const int N = 100000;
int t, n, d[N + 1][4];
char a[2][N + 1];

int main() 
{
	int mex[4] = {0, 1, 0, 2};
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s%s", &n, a[0], a[1]);
		d[0][1] = d[0][2] = d[0][3] = -INF;
		for (int i = 1; i <= n; ++i) {
			int cur = 1 << (a[0][i - 1] - '0') | 1 << (a[1][i - 1] - '0');
			for (int j = 0; j < 4; ++j) d[i][j] = -INF;
			for (int j = 0; j < 4; ++j) d[i][cur | j] = std::max(d[i][cur | j], d[i - 1][j]);
			for (int j = 0; j < 4; ++j) d[i][0] = std::max(d[i][0], d[i][j] + mex[j]);
		}
		printf("%d\n", d[n][0]);
	}
	return 0;
}
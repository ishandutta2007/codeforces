#include <cstdio>
#include <algorithm>

long long gcd(long long a, long long b) 
{
	while (a && b) {
		if (a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

const int N = 200000;
const int L = 65;
int t, n, pos[N][L];
long long a[N], g[N][L];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		g[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", a + i);
			if (i) {
				long long val = a[i] - a[i - 1];
				if (val < 0) val = -val;
				g[i][0] = val;
				pos[i][0] = i;
				for (int j = 0, k = 1; g[i][k - 1] != 1; ++j) {
					long long gg = gcd(g[i - 1][j], val);
					if (gg != g[i][k - 1]) {
						g[i][k] = gg;
						pos[i][k] = pos[i - 1][j];
						ans = std::max(ans, i - pos[i][k]);
						++k;
					}
				}
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
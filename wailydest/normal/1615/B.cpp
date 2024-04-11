#include <cstdio>
#include <algorithm>

const int N = 200005;
const int L = 20;
int t, l, r, sum[L][N];

int main() 
{
	for (int i = 0; i < L; ++i) for (int j = 1; j < N; ++j) sum[i][j] = sum[i][j - 1] + (j >> i & 1 ^ 1);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &l, &r);
		int ans = ~(1 << 31);
		for (int i = 0; i < L; ++i) ans = std::min(ans, sum[i][r] - sum[i][l - 1]);
		printf("%d\n", ans);
	}
	return 0;
}
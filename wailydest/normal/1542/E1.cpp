#include <cstdio>
#include <numeric>
#include <algorithm>
#include <vector>

int md;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}

inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}

const int N = 55;
int n, d[N][N * N], cnt[N], ncr[N][N], fact[N], ps[N][N * N], ans[N];

int main() 
{
	scanf("%d%d", &n, &md);
	ncr[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		ncr[i][0] = ncr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			ncr[i][j] = add(ncr[i - 1][j], ncr[i - 1][j - 1]);\
		}
	}
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	d[0][0] = 1;
	for (int i = 0; i <= n; ++i) for (int j = 0; j < n * n; ++j) {
		ps[i][j] = d[i][j];
		if (j) ps[i][j] = add(ps[i][j], ps[i][j - 1]);
		for (int k = 0; k <= i; ++k) d[i + 1][j + k] = add(d[i + 1][j + k], d[i][j]);
	}
	ans[1] = 0;
	for (int i = 2; i <= n; ++i) {
		ans[i] = add(ans[i], mul(i, ans[i - 1]));
		for (int j = 0; j < i; ++j) {
			for (int k = j + 1; k < i; ++k) {
				int cur = 0;
				for (int p = 0; p < i * (i - 1) / 2; ++p) if (j + p - k - 1 >= 0) ans[i] = add(ans[i], mul(d[i - 1][p], ps[i - 1][j + p - k - 1]));
			}
		}
	}
	printf("%d\n", ans[n] % md);
	return 0;
}
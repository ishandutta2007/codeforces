#include <cstdio>

const int md = 1000000007;
const int inv2 = 500000004;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += md;
	return a;
}
inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}
int po(int a, int b) 
{
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

const int N = 2005;
int t, n, m, k, d[N][N];
double dp[N][N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= i; ++j) {
			if (j == i) d[i][j] = add(d[i - 1][j - 1], k);
			else d[i][j] = add(d[i - 1][j - 1], mul(inv2, sub(d[i - 1][j], d[i - 1][j - 1])));
		}
		printf("%d\n", d[n][m]);
	}
	return 0;
}
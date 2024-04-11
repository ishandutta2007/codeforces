#include <cstdio>
#include <cstring>
#include <cstdlib>

const int md = 1000000007;

inline void addto(int &a, int b) 
{
	a += b;
	if (a >= md) a -= md;
}

inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}

const int N = 2005;
int tc, n, d[N][N << 1], sum[N][N << 1];
char s[N], t[N];

int main() 
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%s%s", &n, s, t);
		for (int i = 0; i <= n; ++i) {
			memset(d[i], 0, N << 3);
			memset(sum[i], 0, N << 3);
		}
		d[0][N] = 1;
		for (int i = 0; i <= n; ++i) {
			for (int c = N - i; c <= N + i; ++c) {
				int ss = sum[i][c];
				addto(ss, mul(abs(c - N), d[i][c]));
				if (i < n) for (int j = 0; j < 2; ++j) if (s[i] == '?' || s[i] == '0' + (j ^ (i & 1))) {
					for (int k = 0; k < 2; ++k) if (t[i] == '?' || t[i] == '0' + (k ^ (i & 1))) {
						if (j == k) {
							addto(d[i + 1][c], d[i][c]);
							addto(sum[i + 1][c], ss);
						} else {
							if (j) {
								addto(d[i + 1][c + 1], d[i][c]);
								addto(sum[i + 1][c + 1], ss);
							} else {
								addto(d[i + 1][c - 1], d[i][c]);
								addto(sum[i + 1][c - 1], ss);
							}
						}
					}
				}
			}
		}
		printf("%d\n", sum[n][N]);
	}
	return 0;
}
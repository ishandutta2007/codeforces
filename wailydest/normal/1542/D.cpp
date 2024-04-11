#include <cstdio>
#include <cstring>

const int md = 998244353;

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

const int N = 500;
int n, d[N + 1][N + 1], a[N + 1];
char type[N + 1];

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf(" %c", type + i);
		if (type[i] == '+') scanf("%d", a + i);
	}
	int ans = 0;
	for (int i = 1, pw = 1; i <= n; ++i) if (type[i] == '+') {
		memset(*d, 0, (N + 1) * (N + 1) << 2);
		d[0][0] = 1;
		for (int j = 1; j < i; ++j) for (int k = 0; k < n; ++k) {
			d[j][k] = d[j - 1][k];
			if (type[j] == '-') {
				d[j][k] = add(d[j][k], d[j - 1][k + 1]);
				if (!k) d[j][k] = add(d[j][k], d[j - 1][0]);
			}
			else if (type[j] == '+' && a[j] < a[i]) d[j][k] = add(d[j][k], k ? d[j - 1][k - 1] : 0);
			else d[j][k] = add(d[j][k], d[j][k]);
		}
		for (int k = 0; k < n; ++k) d[i][k] = d[i - 1][k];
		for (int j = i + 1; j <= n; ++j) for (int k = 0; k < n; ++k) {
			d[j][k] = d[j - 1][k];
			if (type[j] == '-') d[j][k] = add(d[j][k], d[j - 1][k + 1]);
			else if (type[j] == '+' && a[j] <= a[i]) d[j][k] = add(d[j][k], k ? d[j - 1][k - 1] : 0);
			else d[j][k] = add(d[j][k], d[j][k]);
		}
		for (int k = 0; k < n; ++k) ans = add(ans, mul(d[n][k], a[i]));
	}
	printf("%d\n", ans);
	return 0;
}
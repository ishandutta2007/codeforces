#include <bits/stdc++.h>
#define MAXI 1000000
using namespace std;
int n, x, y, a[500005], f[MAXI * 2 + 5];
long long g[MAXI * 2 + 5], nowi, ans;
int prime[MAXI + 5], cnt = 0;
bool flag[MAXI + 5];
long long work(int l, int r)
{
	return (f[r] - f[l - 1]) * (long long)r - (g[r] - g[l - 1]);
}
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 2; i <= MAXI; i++)
	{
		if (!flag[i]) prime[++cnt] = i;
		for  (int j = 1; j <= cnt && 1LL * prime[j] * i <= MAXI; j++)
		{
			flag[prime[j] * i] = true;
			if (!(i % prime[j])) break;
		}
	}
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) f[a[i]]++, g[a[i]] += a[i];
	for (int i = 2; i <= MAXI * 2; i++) f[i] += f[i - 1], g[i] += g[i - 1];
	ans = 1LL << 60;
	int qwq = x / y, qaq;
	for (int i = 1; i <= cnt; i++)
	{
		nowi = 0;
		qaq = min(prime[i] - 1, qwq);
		for (int j = prime[i]; ; j += prime[i])
		{
			nowi += 1LL * y * work(j - qaq, j) + 1LL * x * (f[j - qaq - 1] - f[j - prime[i]]);
			if (j >= MAXI) break;
		}
		ans = min(ans, nowi);
	}
	printf("%I64d\n", ans);
	return 0;
}
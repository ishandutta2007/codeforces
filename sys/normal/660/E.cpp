#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
int n, m;
long long ans;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		(ans += fast_pow(m, n + 1 - i) * fast_pow(2 * m - 1, i - 1)) %= p;
	printf("%lld", (ans + fast_pow(m, n)) % p);
	return 0;
}
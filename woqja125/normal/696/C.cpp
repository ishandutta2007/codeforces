#include<stdio.h>

const int MOD = 1000000007;

long long pow(long long x, long long p)
{
	long long re = 1, pp = x;
	while (p)
	{
		if (p % 2) (re *= pp)%=MOD;
		pp = pp*pp%MOD;
		p /= 2;
	}
	return re;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	long long b = 2, a = 2, t, x=-1;
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &t);
		a = pow(a, t)%MOD;
		b = pow(b, t)%MOD;
		if (t % 2 == 0) x = 1;
	}
	a = a*pow(2, MOD - 2)%MOD;
	b = b*pow(2, MOD - 2) % MOD;
	a = (MOD + a + x)%MOD;
	a = a*pow(3, MOD - 2) % MOD;
	printf("%lld/%lld", a, b);
	return 0;
}
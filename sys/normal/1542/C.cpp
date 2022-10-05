#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;
int T;
long long n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0;
		scanf("%lld", &n);
		long long now = 1;
		int ct = 2;
		while (now <= n)
		{
			(ans += ct * (((n / now) % p) % p)) %= p;
			now = now / __gcd(now, (long long) ct) * ct;
			(ans += p - ct * (((n / now) % p) % p) % p) %= p;
			ct++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
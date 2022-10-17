#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int x;
ll n, z = 1;
ll pw(ll x, ll y)
{
	ll re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
ll gao(ll n, int p)
{
	ll re = 0;
	while (n > 0)
	{
		n /= p;
		re += n;
	}
	return re;
}
int main()
{
	cin >> x >> n;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			while (x % i == 0)
			{
				x /= i;
			}
			z = z * pw(i, gao(n, i)) % mod;
		}
	}
	if (x > 1)
	{
		z = z * pw(x, gao(n, x)) % mod;
	}
	printf("%lld\n", z);
	return 0;
}
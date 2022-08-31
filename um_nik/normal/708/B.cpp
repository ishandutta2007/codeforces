#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll a00, a01, a10, a11;

void Fail()
{
	printf("Impossible\n");
	exit(0);
}

ll getPairs(ll x)
{
	ll n = (ll)sqrt(x * 2) - 2;
	if (n < 1) n = 1;
	while(n * (n - 1) / 2 < x) n++;
	if (n * (n - 1) / 2 == x)
		return n;
	else
		return -1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%lld%lld%lld", &a00, &a01, &a10, &a11);
	ll s = a00 + a01 + a10 + a11;
	if (s == 0)
	{
		printf("0\n");
		return 0;
	}
	ll n = getPairs(s);
	if (n == -1)
		Fail();
	if (a00 == 0 && a01 == 0 && a10 == 0)
	{
		for (int i = 0; i < n; i++)
			printf("1");
		printf("\n");
		return 0;
	}
	if (a11 == 0 && a10 == 0 && a01 == 0)
	{
		for (int i = 0; i < n; i++)
			printf("0");
		printf("\n");
		return 0;
	}
	ll z = getPairs(a00);
	ll on = getPairs(a11);
	if (z == -1 || on == -1 || z + on != n)
		Fail();
	for (int i = 0; i < n; i++)
	{
		if (z > 0 && a01 >= on)
		{
			a01 -= on;
			z--;
			printf("0");
		}
		else if (on > 0 && a10 >= z)
		{
			a10 -= z;
			on--;
			printf("1");
		}
		else throw;
	}
	printf("\n");

	return 0;
}
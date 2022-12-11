#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <complex>
#include <valarray>
#include <cassert>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

ll getCnt(ll x)
{
	for (ll i = 1;; i++)
	{
		ll value = (ll)i * (i - 1) / 2;
		if (value == x)
			return i;
		if (value > x)
			return -1;
	}
}

void fail()
{
	puts("Impossible");
	exit(0);	
}

char str[(int)1e6 + 10];

void printStr(int cnt, char c)
{
	for (int i = 0; i < cnt; i++)
		str[i] = c;
	printf("%s\n", str);
	exit(0);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	ll a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	ll c0 = getCnt(a);
	ll c1 = getCnt(d);
	if (c0 == -1 || c1 == -1)
		fail();
	if (b == 0 && c == 0)
	{
		if (a == 0)
			printStr(c1, '1');
		else if (d == 0)
			printStr(c0, '0');
		else
			fail();
	}
	ll pairs = c0 * c1;
	if (pairs != b + c)
		fail();
	
	int it = 0;
	for (ll l = 0; l < c1; l++)
	{
		ll c01 = c0 * (c1 - l);
		ll c10 = l * c0;
		if (c01 >= b && c01 - c0 <= b)
		{
			ll steps = c01 - b;
			for (int a = 0; a < l; a++)
				str[it++] = '1';
			for (int a = 0; a < c0 - steps; a++)
				str[it++] = '0';
			str[it++] = '1';
			for (int a = 0; a < steps; a++)
				str[it++] = '0';
			for (int a = 0; a < c1 - l - 1; a++)
				str[it++] = '1';
			printf("%s\n", str);
			return 0;
		}
	}
	
	return 0;
}
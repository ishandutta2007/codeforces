#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n;
	scanf("%lld", &n);
	ll x = 2;
	for (ll k = 1; k <= n; k++)
	{
		printf("%lld\n", (k + 1) * (k + 1) * k - x / k);
		x = k * (k + 1);
	}


	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y)
{
	return (y == 0 ? x : gcd(y, x % y));
}
ll lcm(ll x, ll y)
{
	return x * (y / gcd(x, y));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	ll z;
	scanf("%d%lld", &n, &z);
	ll ans = 1;
	while(n--)
	{
		ll x;
		scanf("%lld", &x);
		ans = gcd(z, lcm(ans, x));
	}
	if (ans == z)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
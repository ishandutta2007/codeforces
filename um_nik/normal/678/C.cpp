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
	return (x / gcd(x, y)) * y;
}

int main()
{
	ll n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	if (p < q)
	{
		swap(a, b);
		swap(p, q);
	}

	ll ans = (n / a) * p;
	ans += (n / b - n / lcm(a, b)) * q;
	cout << ans << endl;

	return 0;
}
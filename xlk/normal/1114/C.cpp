#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gao(ll n, ll b)
{
	ll re = 0;
	while (n > 0)
	{
		n /= b;
		re += n;
	}
	return re;
}
int main()
{
	ll n, b, z = 1e18;
	cin >> n >> b;
	for (ll i = 2; i * i <= b; i++)
	{
		if (b % i == 0)
		{
			int c = 0;
			while (b % i == 0)
			{
				b /= i;
				c++;
			}
			z = min(z, gao(n, i) / c);
		}
	}
	if (b > 1)
	{
		z = min(z, gao(n, b));
	}
	cout << z << endl;
	return 0;
}
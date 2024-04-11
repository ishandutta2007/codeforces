#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b)
{
	if(!b)
		return a;
	else
		return gcd(b, a % b);
}

ll f(ll x, ll y, ll step = 0)
{
	if(y == 0)
		return 0;
	else if(x == 1)
		return y;
	ll g = gcd(x, y);
	if(step * step > x)
		return y / x + y % x;
	return 1 + f(x / g, y / g - 1, g == 1 ? step + 1 : 0);
}

int main()
{
	long long x, y;
	while(std::cin >> x >> y)
	{
		std::cout << f(x, y) << '\n';
	}
}
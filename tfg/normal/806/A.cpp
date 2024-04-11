#include <iostream>

typedef long long ll;

bool can(ll x, ll y, ll p, ll q, ll use)
{
	//std::cout << "testing (" << x << ", " << y << ", " << p << ", " << q << ", " << use << ")\n";
	p *= use;
	q *= use;
	if(y > q)
		return false;
	ll delta = p - x;

	if(delta < 0)
		return false;
	//std::cout << "delta is " << delta << " and other is " << q - y << "\n";
	if(q - y >= delta)
		return true;
	else
		return false;
}

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		ll x, y, p, q;
		std::cin >> x >> y >> p >> q;
		ll l, r;
		l = 1;
		r = ll(1e9) + 10;
		while(l != r)
		{
			ll mid = (l + r) / 2;
			if(can(x, y, p, q, mid))
				r = mid;
			else
				l = mid + 1;
		}
		if(can(x, y, p, q, l))
			std::cout << l * q - y << '\n';
		else
			std::cout << "-1\n";
	}
}
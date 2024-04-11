#include <iostream>

typedef long long ll;

int digits(ll x)
{
	if(x == 0)
		return 0;
	else
		return x % 10 + digits(x / 10);
}

int main()
{
	ll n, s;
	std::cin >> n >> s;
	ll l = 0, r = n + 1;
	while(l != r)
	{
		ll mid = (l + r) / 2;
		//std::cout << "on mid " << mid << '\n';
		if(mid - digits(mid) >= s)
		{
			r = mid;
			//std::cout << "got\n";
		}
		else
		{
			l = mid + 1;
			//std::cout << "not\n";
		}
	}
	std::cout << n - r + 1 << '\n';
}
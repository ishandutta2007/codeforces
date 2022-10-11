#include <iostream>
#include <cstdio>

typedef long long ll;

const ll ms = ll(1e6);

ll n, k;

ll comb(ll x)
{
	return ((x + 1) * (x)) / 2;
}

int main()
{
	std::cin >> n >> k;
	if(k >= ms || comb(k) > n)
	{
		std::cout << "-1\n";
		return 0;
	}
	ll ans = 1;
	/*for(int i = 1; i * comb(k) <= n; i++)
	{
		if((n - i * comb(k)) % i == 0)
			ans = i;
	}*/
	for(ll i = 1; i * i <= n; i++)
	{
		if(n % i != 0)
			continue;
		ll divisor = i;
		if((n - divisor * comb(k)) % divisor == 0 && n >= divisor * comb(k))
			ans = std::max(ans, divisor);
		divisor = n / i;
		if((n - divisor * comb(k)) % divisor == 0 && n >= divisor * comb(k))
			ans = std::max(ans, divisor);
	}
	ll missing = n;
	for(ll i = 1; i < k; i++)
	{
		if(i != 1)
			//std::cout << ' ';
			printf(" ");
		//std::cout << i * ans;
		printf("%lli", i * ans);
		missing -= i * ans;
	}
	if(k > 1)
		std::cout << ' ';
	std::cout << missing << '\n';
}
#include <iostream>
#include <cstdio>

typedef long long ll;

const int ms = 1001000;

ll pref[ms];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] ^ i;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		ll temp;
		scanf("%lli", &temp);
		ans ^= temp;
	}
	for(int i = 1; i <= n; i++)
	{
		int groups = n / i;
		int last = n % i;
		if(groups & 1)
			ans ^= pref[i - 1];
		ans ^= pref[last];
	}
	std::cout << ans << '\n';
}
#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long ll;

const int ms = 100100;

ll a[ms];

int main()
{
	int n;
	ll k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++)
		scanf("%lli", a + i);
	std::sort(a, a + n);
	bool valid = true;
	ll ans = 0;
	for(int i = 1; i < n; i++)
	{
		ans += (a[i] - a[0]) / k;
		if((a[i] - a[0]) % k != 0)
			valid = false;
	}
	if(!valid)
		ans = -1;
	std::cout << ans << '\n';
}
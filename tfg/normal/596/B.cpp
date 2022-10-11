#include <iostream>

typedef long long ll;

const int ms = 200200;

int n;
ll a[ms];

ll BIT[ms];

void upd(int x, ll v)
{
	for(; x < ms; x += x & -x)
		BIT[x] += v;
}

ll qry(int x)
{
	ll ans = 0;
	for(; x > 0; x -= x & -x)
		ans += BIT[x];
	return ans;
}

int main()
{
	std::cin >> n;
	for(int i = 1; i <= n; i++)
		std::cin >> a[i];
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ll cur = qry(i);
		ll cost = a[i] - cur;
		upd(i, cost);
		ans += std::max(cost, -cost);
	}
	std::cout << ans << '\n';
}
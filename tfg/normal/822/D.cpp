#include <iostream>
#include <vector>

typedef long long ll;

const int ms = 5 * 1e6 + 100;
const ll MOD = ll(1e9) + 7;
const ll INF = 1e18;

bool np[ms];
ll dp2[ms], where[ms];
std::vector<int> divs[ms];

ll pairs(ll x)
{
	return (x * (x - 1) / 2);
}


ll get_cost(int n, int groups)
{
	//pairs(p * q) * n / (p * q) = O(p * q * n)
	//pairs(p) * n / p + pairs(q) * n / (p * q) = O(p * n + q * n / p) 
	return pairs(groups) * (n / groups);
}

int main()
{
	get_cost(2, 1);
	for(int i = 2; i < ms; i++)
		dp2[i] = INF;
	for(int i = 2; i < ms; i++)
	{
		if(np[i])
			continue;
		divs[i].push_back(i);
		for(int j = i + i; j < ms; j += i)
		{
			np[j] = true;
			if(divs[j].size() == 0)
			divs[j].push_back(i);
		}
	}
	for(int i = 2; i < ms; i++)
	{
		for(auto a : divs[i])
		{
			ll cur_cost = dp2[i / a] + get_cost(i, a);
			//std::cout << "on " << i << " using groups of " << a << " cost is " << cur_cost << '\n';
			dp2[i] = std::min(dp2[i], cur_cost);
		}
	}
	for(int i = 2; i < ms; i++)
		dp2[i] %= MOD;
	//for(int i = 0; i < 20; i++)
	//	std::cout << "(" << i << ", " << dp2[i] << ", " << where[i] << ")\n";
	int t, l, r;
	std::cin >> t >> l >> r;
	ll cur = 1, ans = 0;
	for(int i = l; i <= r; i++)
		ans = (ans + cur * dp2[i]) % MOD, cur = (cur * t) % MOD;
	std::cout << ans << '\n';
}